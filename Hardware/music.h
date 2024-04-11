#ifndef MUSIC_H
#define MUSIC_H

#include "OLED.h"
#include "Delay.h"
#include "songs.h"
#include "key.h"

extern unsigned char* Gmusics[];
extern int songIdx;
extern int isPaused;
extern int isChanged;


void music_init(void);
// void play_music(void);   
void beep(int frequency, int timeWait);  // 蜂鸣器发出指定频率, 指定时间的蜂鸣声 
void set_frequency(int frequency);       // 设置预分频器的预分频值来改变蜂鸣器的频率
void activateSpeaker(void);
void deactivateSpeaker(void);

#endif
