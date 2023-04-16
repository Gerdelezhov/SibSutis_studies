#include <ctest.h>
#include <libmatches/matches.h>
#include <stdio.h>
#include <stdlib.h>

int human_player = 2;
int comp_player = 1;
int result;
char input[10];

CTEST(move_check_suite, down_to_ten_err)
{
    int num, matches_heap;
    for (matches_heap = 1; matches_heap < 11; matches_heap++) {
        for (num = matches_heap + 1; num < 11; num++) {
            ASSERT_EQUAL(-3, move_check(num, matches_heap));
        }
    }
    printf("\n\n");
}

CTEST(move_check_suite, more_than_ten)
{
    int num, matches_heap;
    for (matches_heap = 10; matches_heap < 101; matches_heap++) {
        for (num = 1; num < 11; num++) {
            ASSERT_EQUAL(num, move_check(num, matches_heap));
        }
    }
}

CTEST(move_check_suite, down_to_ten)
{
    int num, matches_heap;
    for (matches_heap = 1; matches_heap < 11; matches_heap++) {
        for (num = 1; num < matches_heap; num++) {
            ASSERT_EQUAL(num, move_check(num, matches_heap));
        }
    }
}

CTEST(first_player_suite, random)
{
    input[0] = 'r';
    ASSERT_INTERVAL(comp_player, human_player, first_player(input));
}

CTEST(first_player_suite, computer)
{
    input[0] = 'c';
    ASSERT_EQUAL(comp_player, first_player(input));
}

CTEST(first_player_suite, player)
{
    input[0] = 'p';
    ASSERT_EQUAL(human_player, first_player(input));
}

CTEST(coputer_move_suite, mod_10)
{
    for (int i = 32; i < 101; i++) {
        if (i % 10 != 0) {
            result = i % 10 - 1;
            if (result == 0) {
                ASSERT_INTERVAL(1, 10, coputer_move(i));
            } else {
                ASSERT_EQUAL(i % 10 - 1, coputer_move(i));
                ASSERT_INTERVAL(1, 10, coputer_move(i));
            }
        }
    }
}

CTEST(coputer_move_suite, twenty_thirty)
{
    for (int i = 22; i < 32; i++) {
        result = i - 21;
        ASSERT_EQUAL(result, coputer_move(i));
        ASSERT_INTERVAL(1, 10, coputer_move(i));
    }
}

CTEST(coputer_mover_suite, null_ten)
{
    int i;
    for (i = 1; i < 11; i++) {
        ASSERT_EQUAL(i, coputer_move(i));
        ASSERT_INTERVAL(1, 10, coputer_move(i));
    }
}

CTEST(player_move_suite, exit)
{
    input[0] = 'q';
    ASSERT_EQUAL(-1, player_move(input));
}

CTEST(player_move_suite, restart)
{
    input[0] = 'n';
    ASSERT_EQUAL(-5, player_move(input));
}