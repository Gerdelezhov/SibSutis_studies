#include <ctest.h>
#include <libchessviz/chessviz.h>
#include <stdlib.h>

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

int step_integer[6] = {1, 1, 0, 1, 3};

CTEST(read_figures, BlackPawn)
{
    ASSERT_EQUAL(0, BlackPawnMove(step_integer, board));
}

CTEST(read_figures, WhitePawn)
{
    step_integer[0] = 1;
    step_integer[1] = 6;
    step_integer[3] = 1;
    step_integer[4] = 5;
    ASSERT_EQUAL(0, WhitePawnMove(step_integer, board));
}

CTEST(read_figures, WhiteHorse)
{
    step_integer[0] = 2;
    step_integer[1] = 7;
    step_integer[3] = 3;
    step_integer[4] = 5;
    ASSERT_EQUAL(0, WhiteHorseMove(step_integer, board));
}

CTEST(read_figures, BlackHorse)
{
    step_integer[0] = 2;
    step_integer[1] = 0;
    step_integer[3] = 3;
    step_integer[4] = 2;
    ASSERT_EQUAL(0, BlackHorseMove(step_integer, board));
}

CTEST(read_figures, WhiteBishop)
{
    step_integer[0] = 3;
    step_integer[1] = 7;
    step_integer[3] = 5;
    step_integer[4] = 5;
    ASSERT_EQUAL(1, BlackHorseMove(step_integer, board));
}

CTEST(Input, InputValidation)
{
    ASSERT_EQUAL(0, InputValidation("e2-e4"));
}