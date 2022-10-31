#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int** genRandMatrix(int size, int maxValue);
int* genRandArray(int size, int maxValue);
void printMatrix(int** matrix);

int main()
{
    srand(time(0));
    int size = rand() % 10;
    int maxValue = 100;
    int** matrix = genRandMatrix(size, maxValue);
    printMatrix(matrix);
    free(matrix);
    return 0;
}

int** genRandMatrix(int size, int maxValue) {
    int** arr = new int* [size + 1];
    arr[0] = new int[1];
    arr[0][0] = size;
    for (int g = 1; g <= size; g++) {
        int size2 = rand() % 10;
        arr[g] = genRandArray(size2, maxValue);
    }
    return arr;
}

int* genRandArray(int size, int maxValue)
{
    int* arr = new int[size + 1];
    arr[0] = size;
    for (int i = 1; i <= size; i++) {
        arr[i] = rand() % maxValue;
    }
    return arr;
}

void printMatrix(int** matrix) {
    cout << matrix[0][0] << '\n';
    for (int i = 1; i <= matrix[0][0]; i++) {
        cout << matrix[i][0] << ":";
        for (int j = 1; j <= matrix[i][0]; j++) {
            cout << " " << matrix[i][j];
        }
        cout << '\n';
    }
}