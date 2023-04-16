#include <libchessviz/chessviz.h>

#include <stdio.h>
#include <stdlib.h>

void conclusion(char board[9][9])
{
    printf("\n");
    int x = 0, y = 0;
    for (y = 0; y < 9; y++) {
        for (x = 0; x < 9; x++) {
            printf("%c ", board[y][x]);
            if (x == 0) {
                printf(" ");
            }
        }
        printf("\n");
        if (y == 7) {
            printf("\n");
        }
    }
}

int BlackPawnMove(int* step_integer, char board[9][9])
{
    if ((step_integer[1] == 1) && (step_integer[4] == step_integer[1] + 2)
        && (board[step_integer[4]][step_integer[3]] == '.')) {
        board[step_integer[4]][step_integer[3]]
                = board[step_integer[1]][step_integer[0]];
        board[step_integer[1]][step_integer[0]] = '.';
        return 0;
    } else if (
            (board[step_integer[4]][step_integer[3]] == '.')
            && (step_integer[4] == step_integer[1] + 1)) {
        board[step_integer[4]][step_integer[3]]
                = board[step_integer[1]][step_integer[0]];
        board[step_integer[1]][step_integer[0]] = '.';
        return 0;
    } else if (
            (board[step_integer[4]][step_integer[3]] > 'A')
            && (board[step_integer[4]][step_integer[3]] < 'Z')
            && (step_integer[4] == step_integer[1] + 1)
            && ((step_integer[3] == step_integer[0] + 1)
                || (step_integer[3] == step_integer[0] - 1))) {
        board[step_integer[4]][step_integer[3]]
                = board[step_integer[1]][step_integer[0]];
        board[step_integer[1]][step_integer[0]] = '.';
        return 0;
    } else
        return 1;
}

int WhitePawnMove(int* step_integer, char board[9][9])
{
    if ((step_integer[1] == 6) && (step_integer[4] == step_integer[1] - 2)
        && (board[step_integer[4]][step_integer[3]] == '.')) {
        board[step_integer[4]][step_integer[3]]
                = board[step_integer[1]][step_integer[0]];
        board[step_integer[1]][step_integer[0]] = '.';
        return 0;
    } else if (
            (board[step_integer[4]][step_integer[3]] == '.')
            && (step_integer[4] == step_integer[1] - 1)) {
        board[step_integer[4]][step_integer[3]]
                = board[step_integer[1]][step_integer[0]];
        board[step_integer[1]][step_integer[0]] = '.';
        return 0;
    } else if (
            (board[step_integer[4]][step_integer[3]] > 'a')
            && (step_integer[4] == step_integer[1] - 1)
            && ((step_integer[3] == step_integer[0] + 1)
                || (step_integer[3] == step_integer[0] - 1))) {
        board[step_integer[4]][step_integer[3]]
                = board[step_integer[1]][step_integer[0]];
        board[step_integer[1]][step_integer[0]] = '.';
        return 0;
    } else
        return 1;
}

int WhiteKingMove(int* step_integer, char board[9][9])
{
    if (((board[step_integer[4]][step_integer[3]] > 'a')
         && (board[step_integer[4]][step_integer[3]] < 'z'))
        || (board[step_integer[4]][step_integer[3]] == '.')) {
        if (((step_integer[0] == step_integer[3] + 1)
             && (step_integer[1] == step_integer[4]))
            || ((step_integer[0] == step_integer[3] - 1)
                && (step_integer[1] == step_integer[4]))
            || ((step_integer[0] == step_integer[3])
                && (step_integer[1] == step_integer[4] + 1))
            || ((step_integer[0] == step_integer[3])
                && (step_integer[1] == step_integer[4] - 1))
            || ((step_integer[0] == step_integer[3] + 1)
                && (step_integer[1] == step_integer[4] + 1))
            || ((step_integer[0] == step_integer[3] + 1)
                && (step_integer[1] == step_integer[4] - 1))
            || ((step_integer[0] == step_integer[3] - 1)
                && (step_integer[1] == step_integer[4] + 1))
            || ((step_integer[0] == step_integer[3] - 1)
                && (step_integer[1] == step_integer[4] - 1))) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else
            return 1;
    } else
        return 1;
}

int BlackKingMove(int* step_integer, char board[9][9])
{
    if (((board[step_integer[4]][step_integer[3]] > 'A')
         && (board[step_integer[4]][step_integer[3]] < 'Z'))
        || (board[step_integer[4]][step_integer[3]] == '.')) {
        if (((step_integer[0] == step_integer[3] + 1)
             && (step_integer[1] == step_integer[4]))
            || ((step_integer[0] == step_integer[3] - 1)
                && (step_integer[1] == step_integer[4]))
            || ((step_integer[0] == step_integer[3])
                && (step_integer[1] == step_integer[4] + 1))
            || ((step_integer[0] == step_integer[3])
                && (step_integer[1] == step_integer[4] - 1))
            || ((step_integer[0] == step_integer[3] + 1)
                && (step_integer[1] == step_integer[4] + 1))
            || ((step_integer[0] == step_integer[3] + 1)
                && (step_integer[1] == step_integer[4] - 1))
            || ((step_integer[0] == step_integer[3] - 1)
                && (step_integer[1] == step_integer[4] + 1))
            || ((step_integer[0] == step_integer[3] - 1)
                && (step_integer[1] == step_integer[4] - 1))) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else
            return 1;
    } else
        return 1;
}

int WhiteRookMove(int* step_integer, char board[9][9])
{
    int j = 0, r = 0;
    if ((step_integer[3] == step_integer[0])
        && (step_integer[4] > step_integer[1])) {
        r = 1;
        for (int i = step_integer[1] + 1; i < step_integer[4]; i++) {
            if (board[i][step_integer[3]] != '.')
                j = 1;
        }
    } else if (
            (step_integer[4] == step_integer[1])
            && (step_integer[3] > step_integer[0])) {
        r = 1;
        for (int i = step_integer[0] + 1; i < step_integer[3]; i++) {
            if (board[step_integer[4]][i] != '.')
                j = 1;
        }
    } else if (
            (step_integer[3] == step_integer[0])
            && (step_integer[1] > step_integer[4])) {
        r = 1;
        for (int i = step_integer[4] + 1; i < step_integer[1]; i++) {
            if (board[i][step_integer[3]] != '.')
                j = 1;
        }
    } else if (
            (step_integer[4] == step_integer[1])
            && (step_integer[0] > step_integer[3])) {
        r = 1;
        for (int i = step_integer[3] + 1; i < step_integer[0]; i++) {
            if (board[step_integer[4]][i] != '.')
                j = 1;
        }
    }
    if ((j == 0) && (r == 1)
        && (((board[step_integer[4]][step_integer[3]] > 'a')
             && (board[step_integer[4]][step_integer[3]] < 'z'))
            || (board[step_integer[4]][step_integer[3]] == '.'))) {
        board[step_integer[4]][step_integer[3]]
                = board[step_integer[1]][step_integer[0]];
        board[step_integer[1]][step_integer[0]] = '.';
        return 0;
    } else
        return 1;
}

int BlackRookMove(int* step_integer, char board[9][9])
{
    int j = 0;
    if ((step_integer[3] == step_integer[0])
        && (step_integer[4] > step_integer[1])) {
        for (int i = step_integer[1] + 1; i < step_integer[4]; i++) {
            if (board[i][step_integer[3]] != '.')
                j = 1;
        }
    } else if (
            (step_integer[4] == step_integer[1])
            && (step_integer[3] > step_integer[0])) {
        for (int i = step_integer[0] + 1; i < step_integer[3]; i++) {
            if (board[step_integer[4]][i] != '.')
                j = 1;
        }
    } else if (
            (step_integer[3] == step_integer[0])
            && (step_integer[1] > step_integer[4])) {
        for (int i = step_integer[4] + 1; i < step_integer[1]; i++) {
            if (board[i][step_integer[3]] != '.')
                j = 1;
        }
    } else if (
            (step_integer[4] == step_integer[1])
            && (step_integer[0] > step_integer[3])) {
        for (int i = step_integer[3] + 1; i < step_integer[0]; i++) {
            if (board[step_integer[4]][i] != '.')
                j = 1;
        }
    }
    if ((j == 0)
        && (((board[step_integer[4]][step_integer[3]] > 'A')
             && (board[step_integer[4]][step_integer[3]] < 'Z'))
            || (board[step_integer[4]][step_integer[3]] == '.'))) {
        board[step_integer[4]][step_integer[3]]
                = board[step_integer[1]][step_integer[0]];
        board[step_integer[1]][step_integer[0]] = '.';
        return 0;
    } else
        return 1;
}

int WhiteBishopMove(int* step_integer, char board[9][9])
{
    if (abs(step_integer[3] - step_integer[0])
        == abs(step_integer[4] - step_integer[1])) {
        int j = 0;
        if ((step_integer[4] < step_integer[1])
            && (step_integer[3] > step_integer[0])) {
            for (int i = 1; i < step_integer[1] - step_integer[4]; i++) {
                if (board[step_integer[1] - i][step_integer[0] + i] != '.')
                    j = 1;
            }
        } else if (
                (step_integer[4] < step_integer[1])
                && (step_integer[0] > step_integer[3])) {
            for (int i = 1; i < step_integer[1] - step_integer[4]; i++) {
                if (board[step_integer[1] - i][step_integer[0] - i] != '.')
                    j = 1;
            }
        } else if (
                (step_integer[1] < step_integer[4])
                && (step_integer[3] > step_integer[0])) {
            for (int i = 1; i < step_integer[4] - step_integer[1]; i++) {
                if (board[step_integer[1] + i][step_integer[0] + i] != '.')
                    j = 1;
            }
        } else if (
                (step_integer[4] > step_integer[1])
                && (step_integer[0] > step_integer[3])) {
            for (int i = 1; i < step_integer[4] - step_integer[1]; i++) {
                if (board[step_integer[1] + i][step_integer[0] - i] != '.')
                    j = 1;
            }
        }
        if ((j == 0)
            && (((board[step_integer[4]][step_integer[3]] > 'a')
                 && (board[step_integer[4]][step_integer[3]] < 'z'))
                || (board[step_integer[4]][step_integer[3]] == '.'))) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else
            return 1;
    } else
        return 1;
}

int BlackBishopMove(int* step_integer, char board[9][9])
{
    if (abs(step_integer[3] - step_integer[0])
        == abs(step_integer[4] - step_integer[1])) {
        int j = 0;
        if ((step_integer[4] < step_integer[1])
            && (step_integer[3] > step_integer[0])) {
            for (int i = 1; i < step_integer[1] - step_integer[4]; i++) {
                if (board[step_integer[1] - i][step_integer[0] + i] != '.')
                    j = 1;
            }
        } else if (
                (step_integer[4] < step_integer[1])
                && (step_integer[0] > step_integer[3])) {
            for (int i = 1; i < step_integer[1] - step_integer[4]; i++) {
                if (board[step_integer[1] - i][step_integer[0] - i] != '.')
                    j = 1;
            }
        } else if (
                (step_integer[1] < step_integer[4])
                && (step_integer[3] > step_integer[0])) {
            for (int i = 1; i < step_integer[4] - step_integer[1]; i++) {
                if (board[step_integer[1] + i][step_integer[0] + i] != '.')
                    j = 1;
            }
        } else if (
                (step_integer[4] > step_integer[1])
                && (step_integer[0] > step_integer[3])) {
            for (int i = 1; i < step_integer[4] - step_integer[1]; i++) {
                if (board[step_integer[1] + i][step_integer[0] - i] != '.')
                    j = 1;
            }
        }
        if ((j == 0)
            && (((board[step_integer[4]][step_integer[3]] > 'A')
                 && (board[step_integer[4]][step_integer[3]] < 'Z'))
                || (board[step_integer[4]][step_integer[3]] == '.'))) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else
            return 1;
    } else
        return 1;
}

void WhiteQueenMove(int* step_integer, char board[9][9])
{
    WhiteBishopMove(step_integer, board);
    WhiteRookMove(step_integer, board);
}

void BlackQueenMove(int* step_integer, char board[9][9])
{
    BlackBishopMove(step_integer, board);
    BlackRookMove(step_integer, board);
}

int WhiteHorseMove(int* step_integer, char board[9][9])
{
    if (((board[step_integer[4]][step_integer[3]] > 'a')
         && (board[step_integer[4]][step_integer[3]] < 'z'))
        || (board[step_integer[4]][step_integer[3]] == '.')) {
        if ((step_integer[4] == step_integer[1] - 2)
            && (step_integer[3] == step_integer[0] + 1)) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else if (
                (step_integer[4] == step_integer[1] - 2)
                && (step_integer[3] == step_integer[0] - 1)) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else if (
                (step_integer[4] == step_integer[1] - 1)
                && (step_integer[3] == step_integer[0] + 2)) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else if (
                (step_integer[4] == step_integer[1] - 1)
                && (step_integer[3] == step_integer[0] - 2)) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else if (
                (step_integer[4] == step_integer[1] + 2)
                && (step_integer[3] == step_integer[0] - 1)) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else if (
                (step_integer[4] == step_integer[1] + 2)
                && (step_integer[3] == step_integer[0] + 1)) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else if (
                (step_integer[4] == step_integer[1] + 1)
                && (step_integer[3] == step_integer[0] + 2)) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else if (
                (step_integer[4] == step_integer[1] + 1)
                && (step_integer[3] == step_integer[0] - 2)) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else
            return 1;
    } else
        return 1;
}

int BlackHorseMove(int* step_integer, char board[9][9])
{
    if (((board[step_integer[4]][step_integer[3]] > 'A')
         && (board[step_integer[4]][step_integer[3]] < 'Z'))
        || (board[step_integer[4]][step_integer[3]] == '.')) {
        if ((step_integer[4] == step_integer[1] - 2)
            && (step_integer[3] == step_integer[0] + 1)) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else if (
                (step_integer[4] == step_integer[1] - 2)
                && (step_integer[3] == step_integer[0] - 1)) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else if (
                (step_integer[4] == step_integer[1] - 1)
                && (step_integer[3] == step_integer[0] + 2)) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else if (
                (step_integer[4] == step_integer[1] - 1)
                && (step_integer[3] == step_integer[0] - 2)) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else if (
                (step_integer[4] == step_integer[1] + 2)
                && (step_integer[3] == step_integer[0] - 1)) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else if (
                (step_integer[4] == step_integer[1] + 2)
                && (step_integer[3] == step_integer[0] + 1)) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else if (
                (step_integer[4] == step_integer[1] + 1)
                && (step_integer[3] == step_integer[0] + 2)) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else if (
                (step_integer[4] == step_integer[1] + 1)
                && (step_integer[3] == step_integer[0] - 2)) {
            board[step_integer[4]][step_integer[3]]
                    = board[step_integer[1]][step_integer[0]];
            board[step_integer[1]][step_integer[0]] = '.';
            return 0;
        } else
            return 1;
    } else
        return 1;
}

int InputValidation(char* step)
{
    while ((step[0] < 'a') || (step[0] > 'h') || (step[2] != '-')
           || (step[4] == '0')) {
        printf("Ошибка: попробуйте сходить по другому\n");
        scanf("%s", step);
    }
    return 0;
}

void WhiteTurn(char board[9][9])
{
    char step[6];
    int flag = 1, step_integer[6];
    scanf("%s", step);
    while (flag == 1) {
        flag = 0;
        InputValidation(step);
        step[0] = step[0] - 96;
        step[1] = abs(step[1] - 56);
        step[3] = step[3] - 96;
        step[4] = abs(step[4] - 56);
        step_integer[0] = step[0];
        step_integer[1] = step[1];
        step_integer[3] = step[3];
        step_integer[4] = step[4];
        switch (board[step_integer[1]][step_integer[0]]) {
        case 'P':
            WhitePawnMove(step_integer, board);
            if (board[step_integer[1]][step_integer[0]] == 'P') {
                flag = 1;
            }
            break;
        case 'N':
            WhiteHorseMove(step_integer, board);
            if (board[step_integer[1]][step_integer[0]] == 'N') {
                flag = 1;
            }
            break;
        case 'K':
            WhiteKingMove(step_integer, board);
            if (board[step_integer[1]][step_integer[0]] == 'K') {
                flag = 1;
            }
            break;
        case 'R':
            WhiteRookMove(step_integer, board);
            if (board[step_integer[1]][step_integer[0]] == 'R') {
                flag = 1;
            }
            break;
        case 'B':
            WhiteBishopMove(step_integer, board);
            if (board[step_integer[1]][step_integer[0]] == 'B') {
                flag = 1;
            }
            break;
        case 'Q':
            WhiteQueenMove(step_integer, board);
            if (board[step_integer[1]][step_integer[0]] == 'Q') {
                flag = 1;
            }
            break;
        default:
            printf("Ошибка: попробуйте сходить по другому\n");
            flag = 1;
        }
    }
}

void BlackTurn(char board[9][9])
{
    char step[6];
    int flag = 1, step_integer[6];
    scanf("%s", step);
    while (flag == 1) {
        flag = 0;
        InputValidation(step);
        step[0] = step[0] - 96;
        step[1] = abs(step[1] - 56);
        step[3] = step[3] - 96;
        step[4] = abs(step[4] - 56);
        step_integer[0] = step[0];
        step_integer[1] = step[1];
        step_integer[3] = step[3];
        step_integer[4] = step[4];
        switch (board[step_integer[1]][step_integer[0]]) {
        case 'p':
            BlackPawnMove(step_integer, board);
            if (board[step_integer[1]][step_integer[0]] == 'p') {
                flag = 1;
            }
            break;
        case 'n':
            BlackHorseMove(step_integer, board);
            if (board[step_integer[1]][step_integer[0]] == 'n') {
                flag = 1;
            }
            break;
        case 'k':
            BlackKingMove(step_integer, board);
            if (board[step_integer[1]][step_integer[0]] == 'k') {
                flag = 1;
            }
            break;
        case 'r':
            BlackRookMove(step_integer, board);
            if (board[step_integer[1]][step_integer[0]] == 'r') {
                flag = 1;
            }
            break;
        case 'b':
            BlackBishopMove(step_integer, board);
            if (board[step_integer[1]][step_integer[0]] == 'b') {
                flag = 1;
            }
            break;
        case 'q':
            BlackQueenMove(step_integer, board);
            if (board[step_integer[1]][step_integer[0]] == 'q') {
                flag = 1;
            }
            break;
        default:
            printf("Ошибка: попробуйте сходить по другому\n");
            flag = 1;
        }
    }
}
