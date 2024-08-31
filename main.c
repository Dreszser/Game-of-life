#include "game_of_life.h"

int main() {
  int time_mili_sec = 500;
  int field[H][W];
  int buffer[H][W] = {0};
  int exit = 1;
  input(field, H, W);
  if (freopen("/dev/tty", "r", stdin)) initscr();
  nodelay(stdscr, 1);
  keypad(stdscr, 1);
  noecho();
  curs_set(0);
  while (exit) {
    output(field, H + 2, W + 2);
    refresh();
    int control_button = getch();
    time_mili_sec = change_speed(control_button, time_mili_sec, &exit);
    life(field, H, W, buffer);
    napms(time_mili_sec);
    erase();
  }
  return 0;
}