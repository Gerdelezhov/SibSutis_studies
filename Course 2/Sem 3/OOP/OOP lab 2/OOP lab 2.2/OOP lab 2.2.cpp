#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int** genRandMatrix(int size) {
    int** arr = new int* [size + 1];
    arr[0] = new int[1];
    arr[0][0] = size;
    for (int g = 1; g <= size; g++) {
        int size2 = rand() % 10 + 1;
        int* arr2 = new int[size2 + 1];
        arr2[0] = size2;
        for (int i = 1; i <= size2; i++) {
            arr2[i] = rand() % 100 + 10;
        }
        arr[g] = arr2;
    }
    return arr;
}

void printMatrix(int** matrix) {
    for (int i = 1; i <= matrix[0][0]; i++) {
        for (int j = 1; j <= matrix[i][0]; j++) {
            cout.width(2);
            cout << " " << matrix[i][j];
        }
        cout << '\n';
    }
}

int main()
{
    srand(time(0));
    int size = 15;
    int** matrix = genRandMatrix(size);
    printMatrix(matrix);
    return 0;
}