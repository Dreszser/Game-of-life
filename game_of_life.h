#ifndef _GAME_OF_LIFE_
#define _GAME_OF_LIFE_

#include <ncurses.h>
#include <stdio.h>

#define H 25
#define W 80

void input(int a[H][W], int n, int m);
void output(int a[H][W], int n, int m);
void life(int a[H][W], int n, int m, int buffer[H][W]);
int count_cells(int a[H][W], int h, int w);
void transfer(int a[H][W], int buffer[H][W]);
int change_speed(int control_button, int time_mili_sec, int *exit);

#endif  // _GAME_OF_LIFE_