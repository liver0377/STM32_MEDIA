#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "key.h"
#include "music.h"
#include "pages.h"
#include "songs.h"
// #include "interrupt.h"
#include <stdio.h>

uint8_t keyNum = 0;
int songIdx = 3;
int isChanged = 1;
int isPaused = 0;
int musicSelect = 0;
unsigned char* music = NULL;

extern int songSize;
extern unsigned char* Gmusics[];

void play_music() {

	int freqSelect = 0;
	int timeWait = 0;
	
    
    songIdx = 0;
    isChanged = 0;
    isPaused = 1;
    musicSelect = 0;
    music = Gmusics[songIdx];
    
	
	while (1) {
        // debug
//        OLED_ShowString(2, 1, "songIdx");
//        OLED_ShowNum(2, 15, songIdx, 1);
//        OLED_ShowString(3, 1, "isPaused");
//        OLED_ShowNum(3, 15, isPaused, 1);
//        OLED_ShowString(4, 1, "music: ");
//        OLED_ShowHexNum(4, 13, (uint32_t)music, 3);

        int   keyNum = Key_GetNum();
        // 1: 上一首 
        // 2: 下一首
        // 3: 暂停


        switch (keyNum) {
            case 1:
              songIdx = (songIdx + 1) >= songSize ? songIdx : (songIdx + 1);
              isChanged = 1;
              music = Gmusics[songIdx];
              musicSelect = 0;
 
              break;
            case 2:
              songIdx = (songIdx - 1) < 0 ? songIdx : (songIdx - 1);
              isChanged = 1;
              music = Gmusics[songIdx];
              musicSelect = 0;
              break;
            case 3:
              isPaused = 1 - isPaused;
              // isPaused ? deactivateSpeaker() : activateSpeaker();
              isChanged = 1;
              break;
            default: break;

       }
        if (isChanged) {
            show_play_page();
            isChanged = 0;
	    }

       if (isPaused) {
          continue; 
       }

        

	   if(music[musicSelect] != 0xFF) {
	        freqSelect = music[musicSelect];
		    musicSelect ++;
		    
		    timeWait = SPEED / 4 * music[musicSelect];
		   
		    beep(65535 - FreqTable[freqSelect], timeWait);
		    musicSelect ++;
	   } else {
		   break;
	   }
	}
}


int main(void)
{
    OLED_Init();
    Key_Init();
    music_init();
    // interrupt_Init();


    songIdx = 0;
    
    show_welcome_page();
    
	while (1)
	{

        play_music();
    } 
}
