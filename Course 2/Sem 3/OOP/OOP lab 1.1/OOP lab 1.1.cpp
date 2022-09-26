#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int* genRandArray(int size, int maxValue);
void print(int* arr);

int* arr;

int main()
{
    srand(time(NULL));
    int size = rand() % 10;
    int maxValue = 100;
    int* arr = genRandArray(size, maxValue);
    print(arr);
    free(arr);
    return 0;
}

int* genRandArray(int size, int maxValue)
{
    arr = new int[size + 1];
    arr[0] = size;
    for (int i = 1; i <= size; i++) {
        arr[i] = rand() % maxValue;
    }
    return arr;
}

void print(int* arr) {
    cout << arr[0] << ":";
    for (int j = 1; j <= arr[0]; j++) {
        cout << " " << arr[j];
    }
}