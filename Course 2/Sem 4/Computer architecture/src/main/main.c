#include <mysimplecomputer.h>
#include <stdio.h>

int
main ()
{
  // memory
  sc_memoryInit ();

  sc_memorySet (5, 15);
  sc_memorySet (7, 8);

  int value1;
  int value2;
  sc_memoryGet (5, &value1);
  sc_memoryGet (7, &value2);
  printf ("В пятой ячейке: %d\nВ седьмой ячейке: %d\n", value1, value2);
  sc_memoryGet (10, &value1);
  printf ("В десятой ячейке: %d\n", value1);

  // files
  printf ("\nСохраним содержимое памяти в файл mem.backup.\n");
  printf ("Зададим новые значения для ячеек 5 и 7:\n");
  sc_memorySave ("mem.backup");
  sc_memorySet (5, 7);
  sc_memorySet (7, 568);
  sc_memoryGet (5, &value1);
  sc_memoryGet (7, &value2);
  printf ("В пятой ячейке: %d\nВ седьмой ячейке: %d\n", value1, value2);
  printf ("Загрузим содержимое памяти из файла mem.backup.\n");
  sc_memoryLoad ("mem.backup");
  sc_memoryGet (5, &value1);
  sc_memoryGet (7, &value2);
  printf ("В пятой ячейке: %d\nВ седьмой ячейке: %d\n", value1, value2);

  // flags
  sc_regInit ();

  printf ("\nИзменим значение флага номер 4 на 1:\n");
  sc_regSet (4, 1);
  sc_regGet (4, &value1);
  printf ("Flag_4: %d\n", value1);

  printf ("Посмотрим содержимое флага номер 1:\n");
  sc_regGet (1, &value1);
  printf ("Flag_1: %d\n", value1);

  printf ("Создадим ситуацию в которой функция 'sc_memorySet' заверштся "
          "ошибкой,\nи посмотрим как изменилось "
          "содержимое флагов:\n");
  sc_memorySet (999, 7);
  sc_regGet (1, &value1);
  printf ("Flag_1: %d\n", value1);

  sc_regGet (4, &value1);
  printf ("Flag_4: %d\n", value1);
  sc_regInit ();

  // operations
  int value = 0;
  int oper = 0;
  int command = 0;

  printf ("\nЗакодируeм операнд 1, команда 21:\n");
  sc_commandEncode (21, 1, &value);
  printf ("Закодированная команда: %d\n", value);

  printf ("Декуодируем полученное значение:\n");
  sc_commandDecode (value, &command, &oper);
  printf ("Команда: %d, Операнд:%d\n", command, oper);

  value = 0;
  sc_regGet (FLAG_WRONG_COMMAND, &value1);
  printf ("\nFLAG_WRONG_COMMAND: %d\n", value1);
  printf ("Закодируeм операнд 1 используя несеществующую команду 999:\n");
  sc_commandEncode (999, 1, &value);
  printf ("Закодированная команда: %d\n", value);
  printf ("Посмотрим флаг отвечающий за ошибку неверной команды:\n");
  sc_regGet (FLAG_WRONG_COMMAND, &value1);
  printf ("FLAG_WRONG_COMMAND: %d\n", value1);

  oper = 0;
  command = 0;
  sc_regSet (FLAG_WRONG_COMMAND, 0);
  sc_regGet (FLAG_WRONG_COMMAND, &value1);
  printf ("\nFLAG_WRONG_COMMAND: %d\n", value1);
  printf ("Декодируем несеществующую команду 9999:\n");
  sc_commandDecode (9999, &command, &oper);
  printf ("Команда: %d, Операнд:%d\n", command, oper);
  printf ("Посмотрим флаг отвечающий за ошибку неверной команды:\n");
  sc_regGet (FLAG_WRONG_COMMAND, &value1);
  printf ("FLAG_WRONG_COMMAND: %d\n", value1);

  return 0;
}
