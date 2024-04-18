#include "key.h"

#include <stdio.h>
/**
  * ��    ����������ʼ��
  * ��    ������
  * �� �� ֵ����
  */
void Key_Init(void)
{

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_11; // | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

    // GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    // GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
}

/**
  * ��    ����������ȡ����
  * ��    ������
  * �� �� ֵ�����°����ļ���ֵ����Χ��0~2������0����û�а�������
  * ע������˺���������ʽ��������������ס����ʱ�������Ῠס��ֱ����������
  */
uint8_t Key_GetNum(void)
{

	uint8_t KeyNum = 0;
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0);
		Delay_ms(20);
		KeyNum = 1;
	}

    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0);
		Delay_ms(20);
		KeyNum = 2;
	}

     if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == 0);
		Delay_ms(20);
		KeyNum = 3;
	}

	return KeyNum;			//���ؼ���ֵ�����û�а������£�����if���������������ΪĬ��ֵ0
}
