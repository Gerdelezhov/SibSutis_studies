#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int size = 9;

int** genRandMatrix(int size, int maxValue) {
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % maxValue;
        }
    }

    return matrix;
}

void filling_A(int** matrix, int* D, int size) {
    cout << endl << "Array_A:" << endl;
    int k = 0;
    int i = 0;
    int j = size - 1;

    while ((i < size) || (j > 1)) {
        int a = i;
        int b = j;
        while ((a < size) && (b < size)) {
            D[k] = matrix[a][b];
            a++;
            b++;
            k++;
        }
        if (j > 0) {
            j--;
        } else {
            i++;
        }
    }
}


void filling_B(int** matrix, int* D, int size) {
    cout << endl << "Array_B:" << endl;
    int k = 0;
    int i = 0;
    int j = 0;

    while ((i < size) && (j >= 0)) {
        int a = i;
        int b = j;
        while ((a < size) && (b >= 0)) {
            D[k] = matrix[a][b];
            a++;
            b--;
            k++;
        }
        if (j < size - 1 && i == 0) {
            j++;
        }
        else {
            j = 0;
            i++;
        }
    }
}

void filling_C(int** matrix, int* D, int size) {
    cout << endl << "Array_C:" << endl;
    int k = 0;
    int  j = size / 2;
    int i = j;
    int u = i;
    int d = i;
    int l = j;
    int r = j;
    int sw = 3;
    while (k != size * size - 1)
    {
        if (i >= 0 && j >= 0 && i < size && j < size) {
            D[k] = matrix[i][j];
            k++;
        }
        switch (sw) {
        case 0:
            i--;
            if (i < u) {
                u = i;
                sw = 1;
            }
            break;
        case 1:
            j++;
            if (j > r) {
                r = j;
                sw = 2;
            }
            break;
        case 2:
            i++;
            if (i > d) {
                d = i;
                sw = 3;
            }
            break;
        case 3:
            j--;
            if (j < l) {
                l = j;
                sw = 0;
            }
            break;
        }
    }

}

void filling_D(int** matrix, int* D, const int size) {
    cout << endl << "Array_D:" << endl;
    int lim = size/2;
    int count = 0;
    int tmp;
    int i, j;
    for (tmp = 0; tmp < lim; tmp++)
    {
        for (i = tmp; i < size - tmp; i++, count++) //колонка вниз
            D[count] = matrix[i][tmp];
        for (j = tmp + 1; j < size - tmp; j++, count++) //строка вправо
            D[count] = matrix[i - 1][j];
        for (i = size - tmp - 2; i >= tmp; i--, count++) //колонка вверх
            D[count] = matrix[i][j - 1];
        for (j = size - tmp - 2; j >= tmp + 1; j--, count++) //строка влево
            D[count] = matrix[i + 1][j];
    }

    if (size % 2 != 0)
        D[count] = matrix[lim][lim];

}

void printMatrix(int** matrix, int size) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout.width(2);
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

void printMass(int* D, int size) {
    for (int i = 0; i < size * size; i++) {
        cout << D[i] << ' ';
    }
}

int main()
{
    const int size = 9;
    int maxValue = 100;

    int** matrix = genRandMatrix(size, maxValue);
    printMatrix(matrix, size);

    int D[size * size];

    filling_A(matrix, D, size);
    printMass(D, size);

    filling_B(matrix, D, size);
    printMass(D, size);

    filling_C(matrix, D, size);
    printMass(D, size);
    
    filling_D(matrix, D, size);
    printMass(D, size);

    free(matrix);
    return 0;
}