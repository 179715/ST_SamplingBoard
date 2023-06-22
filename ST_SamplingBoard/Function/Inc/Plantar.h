/*
*********************************************************************************************************
*
*	�ļ����� : Plantar.h
*	��    �� : V1.0
*	˵    �� : �������ڶ�λ��Ŀѹ�����������еĲɼ�����ͷ�ļ���
*
*	�޸ļ�¼ :
*		�汾��      ����            ����          ˵��
*		V1.0    2023-03-10     Qiuqiu&Meipo    �״η���
*
*	Copyright (C), 2023-2028, c2403336037@mail.dlut.edu.cn
*
*********************************************************************************************************
*/

#ifndef PLANTAR_H
#define PLANTAR_H

/* ���ѹ�������������������� */
#define SENSOR_NUM_TOTAL 45 
#define SENSOR_NUM_LINE 10
#define SENSOR_NUM_COLUMN 6

#include "main.h"


/* LOG��ӡ���� */
#if 1
	#define PLANTAR_LOG     printf
#else
	#define PLANTAR_LOG     (...)
#endif

#define ENABLE      1
#define DISABLE     0


/*
*********************************************************************************************************
*	                                      ��������
*********************************************************************************************************
*/
static inline void Row_Select(uint8_t Row);
static inline void Column_Select(uint8_t Column);
static void Channel_Sampling(uint8_t Row, uint8_t Column);
void Array_Scanning_Sampling();



#endif