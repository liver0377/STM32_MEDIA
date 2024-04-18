#include "pages.h"
#include "key.h"

void show_play_page(void) {
    OLED_Clear();


    int nums[20];
    int cnt = 0;

    char* p = (char*) malloc(20);
    int len = strlen(songToName[songIdx]);
    memset(p, '\0', 20);
    memcpy(p, songToName[songIdx], len);
    
    char *token;
    token = (char*)strtok(p, ", ");  // ʹ�ö��źͿո���Ϊ�ָ���
    while (token != NULL) {
        nums[cnt] = atoi(token);  // ���ַ���ת��Ϊ����
        cnt++;
        token = (char*)strtok(NULL, ", ");
    }
    
    // debug
    // OLED_ShowString(2, 1, "len: ");
    // OLED_ShowNum(2, 14, len, 2);

    for (int i = 0; i < cnt; i ++) {
     int begin_line = 1;
     int begin_column = (16 - cnt * 2) / 2 + 1;
     OLED_ShowChinese(begin_line, begin_column + 2 * i, nums[i]);
    }
    
    free(p);

    // TODO: չʾ����ͼ��
    if (isPaused) {
        OLED_ShowImage(3, 6, 0);  
    } else {
        OLED_ShowImage(3, 6, 1);
    } 
      
}

void show_welcome_page(void) {
   OLED_Clear();
   OLED_ShowString(1, 6, "WELCOME");
}


void show_song(int song_1_or_2, int idx) {
   int nums[20];
    int cnt = 0;

    char* p = (char*) malloc(20);
    int len = strlen(songToName[idx]);
    memset(p, '\0', 20);
    memcpy(p, songToName[idx], len);
    
    char *token;
    token = (char*)strtok(p, ", ");  // ʹ�ö��źͿո���Ϊ�ָ���
    while (token != NULL) {
        nums[cnt] = atoi(token);  // ���ַ���ת��Ϊ����
        cnt++;
        token = (char*)strtok(NULL, ", ");
    }
    
    // debug
    // OLED_ShowString(2, 1, "len: ");
    // OLED_ShowNum(2, 14, len, 2);
    for (int i = 0; i < cnt; i ++) {
        int begin_line = 3 + song_1_or_2 * 2;
        int begin_column = 2;
        OLED_ShowChinese(begin_line, begin_column + 2 * i, nums[i]);
    }

}


void show_menu(void) {
    OLED_Clear();

    // ��ʾ�˵�
    OLED_ShowChinese(1, 1, 15);
    OLED_ShowChinese(1, 3, 16);
   
    OLED_ShowIcon(5, 1, 0);
   show_song(1, songIdx);
   if (songIdx + 1 < songSize) {
      show_song(2, songIdx + 1); 
   }

   
}

