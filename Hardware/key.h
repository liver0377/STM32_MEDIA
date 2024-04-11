#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"                  // Device header
#include "Delay.h"

// DEBUG
#include "OLED.h"

// extern uint8_t KeyNum;

void Key_Init(void);
uint8_t Key_GetNum(void);

#endif