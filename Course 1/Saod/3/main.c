
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 20
int main()
{
    int matrix[SIZE][SIZE]; // матрица связей
    int D[SIZE];       // минимальное расстояние
    int H[SIZE];       // посещенные вершины
    int temp, minindex, min;
    int begin_index = 0;
    int moshn;
    system("clear");
    // Инициализация матрицы связей
    for (int i = 0; i < SIZE; i++) {
        moshn = rand() % 19 + 1;
        matrix[i][i] = 0;
        for (int j = i + 1; j < SIZE; j++) {
            temp = rand() % 89 + 10;
            matrix[i][j] = temp;
            matrix[j][i] = temp;
        }
    }
    // Вывод матрицы
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%5d ", matrix[i][j]);
        printf("\n");
    }
    //Инициализация вершин и расстояний
    for (int i = 0; i < SIZE; i++) {
        D[i] = INT_MAX;
        H[i] = 1;
    }
    D[begin_index] = 0;
    // Шаг алгоритма
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i < SIZE;
             i++) { // Если вершину ещё не обошли и вес меньше min
            if ((H[i] == 1) && (D[i] < min)) { // Переприсваиваем значения
                min = D[i];
                minindex = i;
            }
        }
        // Добавляем найденный минимальный вес
        // к текущему весу вершины
        // и сравниваем с текущим минимальным весом вершины
        if (minindex != 10000) {
            for (int i = 0; i < SIZE; i++) {
                if (matrix[minindex][i] > 0) {
                    temp = min + matrix[minindex][i];
                    if (temp < D[i]) {
                        D[i] = temp;
                    }
                }
            }
            H[minindex] = 0;
        }
    } while (minindex < 10000);
    // Вывод кратчайших расстояний до вершин
    printf("\nКратчайшие расстояния до вершин: \n");
    for (int i = 0; i < SIZE; i++) {
        printf("%5d ", D[i]);
    }
    printf("\n");
    return 0;
}