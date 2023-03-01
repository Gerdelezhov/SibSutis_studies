#include <mysimplecomputer.h>
#include <stdio.h>

int memory_operations_id[DEFAULT_COUNT_MEMORY_OPERATIONS]
    = { 10, 11,         // i/o
        20, 21,         // loading/unloading
        30, 31, 32, 33, // arithmetic
        40, 41, 42, 43, // control transfer
        51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
        64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76 };
int memory[MEM_SIZE];
int flag = 0;

int
sc_memoryInit ()
{
  int i;
  for (i = 0; i < MEM_SIZE; i++)
    memory[i] = 0;
  return 0;
}

int
sc_memorySet (int address, int value)
{
  if (address < 0 || address >= MEM_SIZE)
    {
      sc_regSet (FLAG_MEM_OUT, 1);
      return -1;
    }
  memory[address] = value;
  return 0;
}

int
sc_memoryGet (int address, int *value)
{
  if (address < 0 || address >= MEM_SIZE)
    {
      sc_regSet (FLAG_MEM_OUT, 1);
      return -1;
    }
  *value = memory[address];
  return 0;
}

int
sc_memorySave (char *filename)
{
  FILE *fp = fopen (filename, "wb");
  if (fp == NULL)
    return -1;
  fwrite (memory, sizeof (int), MEM_SIZE, fp);
  fclose (fp);
  return 0;
}

int
sc_memoryLoad (char *filename)
{
  FILE *fp = fopen (filename, "rb");
  if (fp == NULL)
    return -1;
  fread (memory, sizeof (int), MEM_SIZE, fp);
  fclose (fp);
  return 0;
}

int
sc_regInit ()
{
  flag = 0;
  return 0;
}

int
sc_regSet (int regist, int value)
{
  if (value == 1)
    flag |= regist;
  else if (value == 0)
    flag &= ~regist;
  else
    return -1;
  return 0;
}

int
sc_regGet (int regist, int *value)
{
  *value = (flag & regist) > 0;
  return 0;
}

int
sc_commandEncode (int command, int operand, int *value)
{
  int true_command = -1;
  for (int i = 0; i < DEFAULT_COUNT_MEMORY_OPERATIONS; i++)
    {
      if (command == memory_operations_id[i])
        true_command = 0;
    }
  if (true_command == -1)
    {
      sc_regSet (FLAG_WRONG_COMMAND, 1);
      return -1;
    }
  else
    {
      if (operand >= 0 && operand < MEM_SIZE)
        {
          *value = (command << 7) | operand; // 7 младших разрядов под операнд
          return 0;
        }
      else
        {
          sc_regSet (FLAG_MEM_OUT, 1);
          return -1;
        }
    }
}

int
sc_commandDecode (int value, int *command, int *operand)
{
  int true_command = -1;
  int attr;
  int buf_Command;
  int buf_Operand;

  attr = (value >> 14) & 1;
  if (attr == 0)
    {
      buf_Command = (value >> 7) & 0x7F; // 127 1111111
      buf_Operand = value & 0x7F;
      for (int i = 0; i < DEFAULT_COUNT_MEMORY_OPERATIONS; i++)
        {
          if (buf_Command == memory_operations_id[i])
            {
              true_command = 0;
            }
        }
      if ((true_command == 0)
          && ((buf_Operand >= 0) && (buf_Operand < MEM_SIZE)))
        {
          *command = buf_Command;
          *operand = buf_Operand;
        }
      else if (true_command == -1)
        {
          sc_regSet (FLAG_WRONG_COMMAND, 1);
          return -1;
        }
      return 0;
    }
  else
    {
      return -1;
    }
}
