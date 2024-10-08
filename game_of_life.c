#include "game_of_life.h"

// Scan .txt file to get starting screen
void input(int a[H][W], int n, int m) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
}

// Function that draws the field in the terminal
void output(int a[H][W], int n, int m) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == 0 || i == n - 1) {
        printw("=");
      } else if (j == 0 || j == m - 1) {
        printw("|");
      } else {
        if (a[i - 1][j - 1] == 0) {
          printw(" ");
        } else {
          printw("o");
        }
      }
    }
    printw("\n");
  }
}

// Main logic of the game
void life(int a[H][W], int n, int m, int buffer[H][W]) {
  int number_of_cells;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      number_of_cells = count_cells(a, i, j);
      if (a[i][j] == 0 && number_of_cells == 3) {
        buffer[i][j] = 1;
      } else if (a[i][j] == 1 && (number_of_cells < 2 || number_of_cells > 3)) {
        buffer[i][j] = 0;
      } else {
        buffer[i][j] = a[i][j];
      }
    }
  }
  transfer(a, buffer);
}

// Support function that counts surrounding cells
int count_cells(int a[H][W], int h, int w) {
  int count = 0;
  int temp_i = h - 1;
  int temp_j = w - 1;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (temp_i + i < 0) {
        temp_i += H;
      }
      if (temp_i + i >= H) {
        temp_i -= H;
      }
      if (temp_j + j < 0) {
        temp_j += W;
      }
      if (temp_j + j >= W) {
        temp_j -= W;
      }
      if (!(temp_i + i == h && temp_j + j == w) &&
          a[temp_i + i][temp_j + j] == 1) {
        ++count;
      }
    }
  }
  return count;
}

// Simple copy from buffer matrix
void transfer(int a[H][W], int buffer[H][W]) {
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      a[i][j] = buffer[i][j];
    }
  }
}

// Speed control function using ncurses ibrary
int change_speed(int control_button, int time_mili_sec, int *exit) {
  switch (control_button) {
    case '1':
      time_mili_sec = 900;
      break;

    case '2':
      time_mili_sec = 800;
      break;

    case '3':
      time_mili_sec = 700;
      break;

    case '4':
      time_mili_sec = 600;
      break;

    case '5':
      time_mili_sec = 500;
      break;

    case '6':
      time_mili_sec = 400;
      break;

    case '7':
      time_mili_sec = 300;
      break;

    case '8':
      time_mili_sec = 200;
      break;

    case '9':
      time_mili_sec = 100;
      break;

    case KEY_DOWN:
      time_mili_sec += 100;
      if (time_mili_sec > 10000) {
        time_mili_sec = 10000;
      }
      break;

    case KEY_UP:
      time_mili_sec -= 100;
      if (time_mili_sec < 10) {
        time_mili_sec = 10;
      }
      break;

    case 'p':
      getchar();
      break;

    case 0x1B:
      endwin();
      *exit = 0;
      break;
  }
  return time_mili_sec;
}