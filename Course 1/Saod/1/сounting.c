#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}
 
int main()
{
    int shir = 950000;
    int mass[shir], prom[100001];
    int i = 0, b = 0, j = 0;
    double start, end;

    for(i = 0; i < shir; i++) //заполнение сортируемого массива
    {
        mass[i] = getrand(0, 100000);
    }

    for(i = 0; i < 100001; i++) //заполнение нулями вспомогательного массива
    {
        prom[i] = 0;
    }

    start = wtime();
    for(i = 0; i < shir; i++)
    {
        prom[mass[i]] += 1;
    }
    for(j = 0; j < 100001; j++)
    {
        for(i = 0; i < prom[j]; i++)
        {
            mass[b] = j;
            b++;
        }  
    }
    end = wtime();
    

    printf("%f\n", (end - start));
    return(0);
}