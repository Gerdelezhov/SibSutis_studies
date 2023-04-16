#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int first_player(char input[10])
{
    int player;
    if (input[0] == 'c') {
        player = 1;
    } else if (input[0] == 'p') {
        player = 2;
    } else {
        player = rand() % 2 + 1;
    }
    return (player);
}

int move_check(int num, int matches_heap)
{
    int correct = 1;
    if (num < 1 || num > 10) {
        system("clear");
        printf("Ошибка! \nКоличество спичек должнобыть от 1 до 10.\n");
        correct = 0;
    } else if (num > matches_heap) {
        system("clear");
        printf("Ошибка! \nВы берете спичек больше чем есть в куче.\n");
        correct = 0;
    }
    if (correct == 0) {
        printf("В куче %d спичек.\n", matches_heap);
        printf("Введите другое количество спичек ('q' - для выхода, 'n' - для "
               "перезапуска):");
        return (-3);
    }
    return (num);
}

int player_move(char input[10])
{
    int num;
    if (input[0] == 'q') {
        return (-1);
    } else if (input[0] == 'n') {
        return (-5);
    }
    num = atoi(input);
    return (num);
}

int coputer_move(int matches_heap)
{
    int num;
    num = rand() % 10 + 1;
    if (matches_heap % 10 != 0) {
        num = (matches_heap % 10 - 1);
        if (num == 0) {
            num = rand() % 10 + 1;
        }
    }
    if (matches_heap > 21 && matches_heap < 32) {
        num = matches_heap - 21;
    }
    if (matches_heap <= 10) {
        num = matches_heap;
    }
    return (num);
}