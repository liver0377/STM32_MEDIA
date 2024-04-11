#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "stm32f10x.h"                  // Device header
#include "OLED.h"

extern int songIdx;
extern int isChanged;
extern int isPauesed;
extern int musicSelect;
extern int songSize;
extern unsigned char* Gmusics[];
extern unsigned char* music;
extern uint8_t is_interrupted;

void interrupt_Init(void);
#endif
