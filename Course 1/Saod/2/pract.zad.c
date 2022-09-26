#include <stdio.h>

void primes(int num)
{
    int mas[num + 1];

        for (int i = 0; i < num + 1; i++) {
        mas[i] = i;
    }

    for (int i = 2; i < num+1; i++) {
        if (mas[i] != 0) {
            for (int j = i * 2; j < num+1; j += i) {
                if (j == 200001){
                    printf("%d ", i);
                }
                mas[j] = 0;
            }
        }
    }
    if (mas[num] == num){
        printf("\n%d - простое число.", num);
    } else {
        printf("\n%d - НЕ простое число.", num);
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    primes(num);
    return(0);
}