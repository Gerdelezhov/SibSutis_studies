#include <mysimplecomputer.h>
#include <myterm.h>
#include <stdio.h>
#include <unistd.h>

void show_interface ();
void print_memory ();
void print_flags ();
void print_keys ();
void str_write (const char *str);

int
main ()
{
  sc_memoryInit ();
  sc_memorySet (5, 2689);
  sc_memorySet (7, 8);
  sc_memorySet (0, 33023); // 33023 = 1000000011111111
  show_interface ();
  return 0;
}

void
str_write (const char *str)
{
  int len = 0;
  while (str[len] != '\0')
    { // вычисляем длину строки
      len++;
    }
  write (STDOUT_FILENO, str, len); // выводим строку на экран
}

void
show_interface ()
{
  mt_clrscr ();
  print_memory ();
  print_flags ();
  print_keys ();
  printf ("\n");
}

void
print_memory ()
{
  mt_gotoXY (28, 1);
  printf ("Memory\n");
  char buf[7];
  int value;
  int sign;
  int high;
  int low;
  int addr = 0;
  for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
        {
          sc_memoryGet (addr, &value);
          sc_memoryDecode (value, &sign, &high, &low);
          snprintf (buf, 7, "%c%02X%02X ", (sign < 0) ? '-' : '+', high, low);
          write (1, buf, 6);
          addr++;
        }
      printf ("\n");
    }
}

void
print_flags ()
{
  mt_gotoXY (69, 10);
  str_write ("flags");

  mt_gotoXY (69, 11);
  str_write ("O E V M");
}

void
print_keys ()
{
  mt_gotoXY (47, 13);
  str_write (" Keys: ");
  mt_gotoXY (47, 14);
  str_write ("l  - load");
  mt_gotoXY (47, 15);
  str_write ("s  - save");
  mt_gotoXY (47, 16);
  str_write ("r  - run");
  mt_gotoXY (47, 17);
  str_write ("t  - step");
  mt_gotoXY (47, 18);
  str_write ("i  - reset");
  mt_gotoXY (47, 19);
  str_write ("F5 - accumulator");
  mt_gotoXY (47, 20);
  str_write ("F6 - instructionCounter");
}