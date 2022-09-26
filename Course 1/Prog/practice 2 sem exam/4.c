//Перевод числа в строковое представление
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void int_to_str(int a, char *str)
{
    int g = a, k = 0;
    for (k = 0; g != 0; k++) {
        g /= 10;
    }

    int b;
    int i, t = k;
    for (i = 0; i < t; i++) {
        b = ((int)(a / (pow(10, k - 1))) % 10);
        str[i] = b + '0';
        k--;
    }
    str[i] = '\0';
}

int main(int argc, char const *argv[])
{
    char str[200];
    int_to_str(192, str);
    printf("%s\n", str);
    return 0;
}
