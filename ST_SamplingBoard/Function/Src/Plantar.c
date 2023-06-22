/*
*********************************************************************************************************
*
*	�ļ����� : Plantar.cpp
*	��    �� : V1.0
*	˵    �� : �������ڶ�λ��Ŀѹ�����������еĲɼ������ļ���
*
*	�޸ļ�¼ :
*		�汾��      ����            ����          ˵��
*		V1.0    2023-03-10     Qiuqiu&Meipo    �״η���
*
*	Copyright (C), 2023-2028, c2403336037@mail.dlut.edu.cn
*
*********************************************************************************************************
*/

#include "Plantar.h"

#define NOP do { __asm__ __volatile__ ("nop"); } while (0)

/**
 * @brief nop_delay
 */
void inline nop_delay(uint8_t num)
{
    while(num)
    {
        NOP;
        num--;
    }
}

/**
 * @brief Row_Select ������ѡͨ
 * @param uint8_t Row  ѡͨ��
 */
static inline void Row_Select(uint8_t Row)
{
    if (Row < 5)            //ѡͨ����ǰ������
    {
        /* ������ѡͨ��ǰ���У� */
        MUX_SetPin(GATE_R0_GPIO, GATE_R0_PIN, (Row & 0b001) >> 0);
        MUX_SetPin(GATE_R1_GPIO, GATE_R1_PIN, (Row & 0b010) >> 1);
        MUX_SetPin(GATE_R2_GPIO, GATE_R2_PIN, (Row & 0b100) >> 2);
        MUX_SetPin(EN_INH2_GPIO, EN_INH2_PIN, ENABLE);      //�ߵ�ƽ-ʹ��ѡͨ��
        MUX_SetPin(EN_INH3_GPIO, EN_INH3_PIN, DISABLE);     //�͵�ƽ-����ѡͨ��
    } 
    else                    //ѡͨ���ں�������
    {
        Row -= 5;
        /* ������ѡͨ�������У� */
        MUX_SetPin(GATE_R3_GPIO, GATE_R3_PIN, (Row & 0b001) >> 0);
        MUX_SetPin(GATE_R4_GPIO, GATE_R4_PIN, (Row & 0b010) >> 1);
        MUX_SetPin(GATE_R5_GPIO, GATE_R5_PIN, (Row & 0b100) >> 2);
        MUX_SetPin(EN_INH2_GPIO, EN_INH2_PIN, DISABLE);     //�ߵ�ƽ-ʹ��ѡͨ��
        MUX_SetPin(EN_INH3_GPIO, EN_INH3_PIN, ENABLE);      //�͵�ƽ-����ѡͨ��

    }
}

/**
 * @brief Column_Select ������ѡͨ
 * @param uint8_t Column  ѡͨ��
 */
static inline void Column_Select(uint8_t Column)
{
    /* ������ѡͨ */
    MUX_SetPin(GATE_C0_GPIO, GATE_C0_PIN, (Column & 0b001) >> 0);
    MUX_SetPin(GATE_C1_GPIO, GATE_C1_PIN, (Column & 0b010) >> 1);
    MUX_SetPin(GATE_C2_GPIO, GATE_C2_PIN, (Column & 0b100) >> 2);
    MUX_SetPin(EN_INH1_GPIO, EN_INH1_PIN, ENABLE);      //�ߵ�ƽ-ʹ��ѡͨ��    
}
