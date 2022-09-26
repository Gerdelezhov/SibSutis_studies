//Разбиение строки на поля и ее восстановление после разбиения.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stok(char *source, char dest[][1000], char symb)
{
    int g = 0, j = 0;
    for (int i = 0; source[i] != '\0'; i++) {
        if (source[i] == symb) {
            dest[j][g] = '\0';
            g = 0;
            j++;
            continue;
        }
        dest[j][g] = source[i];
        g++;
    }
    return j + 1;
}

void scat(char *source, char *ins)
{
    int j = strlen(source);
    for (int i = 0; ins[i] != '\0'; i++) {
        source[j] = ins[i];
        j++;
    }
    source[j] = '\0';
}

void restore(char source[][1000], char *dest, char symb, int k)
{
    int i;
    for (i = 0; i < k; i++) {
        scat(dest, source[i]);
        scat(dest, "G");
    }
    // dest[i] = '\0';
}


int main(int argc, char const *argv[])
{
    char dest[20][1000];
    char source[1000] = "abobaGtyuioopGebenegrGhg45rh";
    int k = stok(source, dest, 'G');

    for (int i = 0; i < k; i++) {
        printf("%s ", dest[i]);
    }
    printf("\n");

    char buf[1000] = {0};
    restore(dest, buf, 'G', k);

    printf("%s ", buf);
    printf("\n");

    return 0;
}