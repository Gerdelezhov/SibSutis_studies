#include <myterm.h>
#include <stdio.h>

int
main ()
{
  int rows, cols;
  mt_clrscr ();

  mt_getscreensize (&rows, &cols);
  printf ("Размер экрана: %dx%d\n", cols, rows);

  mt_setfgcolor (RED);
  printf ("Текст красного цвета\n");

  mt_setbgcolor (YELLOW);
  printf ("Текст на желтом фоне\n");

  mt_gotoXY (cols / 2, rows / 2);
  printf ("Текст по центру экрана\n");

  mt_setfgcolor (WHITE);

  mt_setbgcolor (BLUE);
  printf ("Текст на синем фоне с белым цветом\n");

  return 0;
}