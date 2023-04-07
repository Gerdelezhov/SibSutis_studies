#pragma once

// ANSI escape-последовательности для управления курсором
#define ANSI_CLEAR_SCREEN "\033[2J"
#define ANSI_MOVE_CURSOR_TOP_LEFT "\033[H"
#define ANSI_MOVE_CURSOR_FORMAT "\033[%d;%dH"

// ANSI escape-последовательности для установки цвета текста и фона
#define ANSI_COLOR_FORMAT "\033[%d;%dm"
#define ANSI_COLOR_RESET "\033[0m"

typedef enum
{
  BLACK = 30,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE
} colors;

int mt_clrscr (void);
int mt_gotoXY (int x, int y);
int mt_getscreensize (int *rows, int *cols);
int mt_setfgcolor (colors color);
int mt_setbgcolor (colors color);