#include "pages.h"


void show_play_page(void) {
    OLED_Clear();


    int nums[20];
    int cnt = 0;

    char* p = (char*) malloc(20);
    int len = strlen(songToName[songIdx]);
    memset(p, '\0', 20);
    memcpy(p, songToName[songIdx], len);
    
    char *token;
    token = (char*)strtok(p, ", ");  // 使用逗号和空格作为分隔符
    while (token != NULL) {
        nums[cnt] = atoi(token);  // 将字符串转换为整数
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

    // TODO: 展示播放图标
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
