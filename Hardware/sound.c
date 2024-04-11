#include "stm32f10x.h"                  // Device header
#include "playmusic.H"
#include "stm32f10x.h"           
#include "OLED.h"
#include "Delay.h"
#include "musics.h"


// 播放音乐
void B_Music(void)
{
	
	OLED_Init();
	Music_Init();

	OLED_ShowString(2,1,"tone:");
	OLED_ShowString(1,1,"JAY-CHOU YYDS");
	int c;

	int musicSelect = 0;
	int freqSelect = 0;
	int timeWait = 0;
	c = 5;
	unsigned char *Music = Musics[3];
	while (1) {
	   if(Music[musicSelect] != 0xFF) {
	        freqSelect = Music[musicSelect];
		    musicSelect ++;
		    
		    timeWait = SPEED / 4 * Music[musicSelect];
		   
		    Play_Music(65535 - FreqTable[freqSelect], timeWait, c);
		    musicSelect ++;
		    
	   }
	}
	
}
