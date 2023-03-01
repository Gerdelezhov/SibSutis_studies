#pragma once

#define MEM_SIZE 100
#define DEFAULT_COUNT_MEMORY_OPERATIONS 38
#define FLAG_MEM_OUT 1
#define FLAG_INVALID_OP 2
#define FLAG_WRONG_COMMAND 3

int sc_memoryInit ();
int sc_memorySet (int address, int value);
int sc_memoryGet (int address, int *value);
int sc_memorySave (char *filename);
int sc_memoryLoad (char *filename);
int sc_regInit ();
int sc_regSet (int reg, int value);
int sc_regGet (int reg, int *value);
int sc_commandEncode (int command, int operand, int *value);
int sc_commandDecode (int value, int *command, int *operand);
