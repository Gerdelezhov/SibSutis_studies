#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void heapyfi(int mass[], int shir, int i)
{
    int l, r, large, prom;
    l = (2 * i) + 1;
    r = (2 * i) + 2;
    large = i;
    if (l < shir && mass[l] > mass[large]) {
        large = l;
    }

    if (r < shir && mass[r] > mass[large]) {
        large = r;
    }

    if (large != i) {
        prom = mass[i];
        mass[i] = mass[large];
        mass[large] = prom;
        heapyfi(mass, shir, large);
    }
}

int main()
{
    int i = 0, shir;
    for (shir = 50000; shir <= 1000000; shir += 50000) {
        int mass[shir];
        for (i = 0; i < shir; i++) //заполнение сортируемого массива
        {
            mass[i] = getrand(0, 100000);
        }

        for (i = shir / 2 - 1; i > 0; i--) {
            heapyfi(mass, shir, i);
        }

        int i = 0;
        for (i = shir - 1; i > 0; i--) {
            swap(mass[0], mass[i]);
        }

        for (i = 0; i < 20; i++) {
            printf("%d ", mass[i]);
        }
        printf("\n");
    }

    return (0);
}