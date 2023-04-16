#pragma once

void conclusion(char board[9][9]);
int BlackPawnMove(int* step_integer, char mass[9][9]);
int WhitePawnMove(int* step_integer, char mass[9][9]);
int WhiteKingMove(int* step_integer, char mass[9][9]);
int BlackKingMove(int* step_integer, char mass[9][9]);
int WhiteRookMove(int* step_integer, char mass[9][9]);
int BlackRookMove(int* step_integer, char mass[9][9]);
int WhiteBishopMove(int* step_integer, char mass[9][9]);
int BlackBishopMove(int* step_integer, char mass[9][9]);
void WhiteQueenMove(int* step_integer, char mass[9][9]);
void BlackQueenMove(int* step_integer, char mass[9][9]);
int WhiteHorseMove(int* step_integer, char mass[9][9]);
int BlackHorseMove(int* step_integer, char mass[9][9]);
int InputValidation(char* step);
void WhiteTurn(char mass[9][9]);
void BlackTurn(char mass[9][9]);
