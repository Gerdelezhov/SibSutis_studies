#include "../libchessviz/chessviz.h"

#include <stdio.h>

int main()
{
    char board[9][9]
            = {"8rnbqkbnr",
               "7pppppppp",
               "6........",
               "5........",
               "4........",
               "3........",
               "2PPPPPPPP",
               "1RNBQKBNR",
               " abcdefgh"};
    int MoveNumber = 1;
    int j = 1;
    conclusion(board);
    while (j == 1) {
        printf("%d.", MoveNumber);
        WhiteTurn(board);
        conclusion(board);
        BlackTurn(board);
        conclusion(board);
        MoveNumber += 1;
    }
}
