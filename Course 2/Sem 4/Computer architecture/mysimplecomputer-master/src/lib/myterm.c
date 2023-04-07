#include <myterm.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

int
mt_clrscr (void)
{
  char *buffer = ANSI_CLEAR_SCREEN ANSI_MOVE_CURSOR_TOP_LEFT;
  ssize_t size = strlen (buffer) + 1;

  if (write (STDOUT_FILENO, buffer, size) < 0)
    {
      return -1;
    }

  return 0;
}

int
mt_gotoXY (int x, int y)
{
  char buffer[16];
  ssize_t size
      = snprintf (buffer, sizeof (buffer), ANSI_MOVE_CURSOR_FORMAT, y, x);

  if (write (STDOUT_FILENO, buffer, size) < 0)
    {
      return -1;
    }

  return 0;
}

int
mt_getscreensize (int *rows, int *cols)
{
  struct winsize w;

  if (ioctl (STDOUT_FILENO, TIOCGWINSZ, &w) != 0)
    {
      return -1;
    }

  *rows = w.ws_row;
  *cols = w.ws_col;
  return 0;
}

int
mt_setfgcolor (colors color)
{
  char buffer[16];
  ssize_t size
      = snprintf (buffer, sizeof (buffer), ANSI_COLOR_FORMAT, 0, color);

  if (write (STDOUT_FILENO, buffer, size) < 0)
    {
      return -1;
    }

  return 0;
}

int
mt_setbgcolor (colors color)
{
  char buffer[16];
  ssize_t size
      = snprintf (buffer, sizeof (buffer), ANSI_COLOR_FORMAT, 1, color + 10);

  if (write (STDOUT_FILENO, buffer, size) < 0)
    {
      return -1;
    }

  return 0;
}