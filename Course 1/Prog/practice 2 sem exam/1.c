//Задача проверки корректности IP адреса узла.
#include <stdio.h>
#include <stdlib.h>

void stok(char *source, char **dest, char symb)
{
    int j = 0, g = 0;
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
}

int ip_check(char **dest)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; dest[i][j] != '\0'; j++) {
            if (dest[i][j] > '9' || dest[i][j] < '0') {
                return 0;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (atoi(dest[i]) > 255 || atoi(dest[i]) < 0) 
            return 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    char ip[] = "192.168.12.45";
    char **dest = malloc(4 * sizeof(char*));
    for(int i = 0; i < 4; i++) {
        dest[i] = malloc(200 * sizeof(char));
    }

    // char dest[4][200];
    stok(ip, dest, '.');

    for (int i = 0; i < 4; i++) {
        printf("%s ", dest[i]);
    }
    printf("\n");

    printf("%d\n", ip_check(dest));

    for (int i = 0; i < 4; i++) {
        free(dest[i]);
    }
    free(dest);
    return 0;
}