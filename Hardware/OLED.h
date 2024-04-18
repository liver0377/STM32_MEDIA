#ifndef __OLED_H
#define __OLED_H

#include "stm32f10x.h"                  // Device header
#include "OLED_Font.h"

extern const uint8_t OLED_F8x16[][16];
extern const uint8_t OLED_F16X16[][32];
extern const uint8_t OLED_IMAGE_bofang[];
extern const uint8_t OLED_IMAGE_bofang[];
extern const uint8_t* OLED_IMAGES [];
extern const uint8_t* OLED_ICONS [];


void OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowChinese(uint8_t Line, uint8_t Column, uint8_t idx);
void OLED_ShowImage(uint8_t Line, uint8_t Column, uint8_t idx);
void OLED_ShowIcon(uint8_t Line, uint8_t Column, uint8_t idx);
#endif
