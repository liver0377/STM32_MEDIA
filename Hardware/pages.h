#ifndef PAGES_H
#define PAGES_H

#include "OLED.h"
#include <stdlib.h>
#include "songs.h"
#include <string.h>

extern int songIdx;
extern int isPaused;
extern char* songToName[];

void show_play_page(void);
void show_welcome_page(void);

#endif
