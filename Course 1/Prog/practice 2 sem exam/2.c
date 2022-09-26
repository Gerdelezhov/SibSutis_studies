//Вставка/удаление фрагмента строки.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scat(char *dst, char *src, char *ins)
{
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dst[i] = src[i];
    }
    for (int j = 0; ins[j] != '\0'; j++) {
        dst[i] = ins[j];
        i++;
    }
    dst[i] = '\0';
}

void strinsert(char *source, char *ins, int pos, char *dst2)
{
    char sec[200];
    int g = 0;
    for (int i = pos; source[i] != '\0'; i++) {
        sec[g] = source[i];
        g++;
    }
    sec[g] = '\0';
    source[pos] = '\0';
    char dst[200];
    scat(dst, source, ins);
    
    scat(dst2, dst, sec);
}

void strdel(char *source, int from, int to, char *dst)
{
    char buf[200];
    int g = 0;
    // strcpy(source + to, buf);
    for (int i = to; source[i] != '\0'; i++) {
        buf[g] = source[i];
        g++;
    }
    buf[g] = '\0';
    source[from] = '\0';
    scat(dst, source, buf);
}

int main(int argc, char const *argv[])
{
    char a[] = "abcdefghi";
    char b[] = " ty ";
    
    char dst2[200];
    // strinsert(a, b, 2, dst2);
    strdel(a, 2, 5, dst2);
    printf("%s\n", dst2);
    return 0;
}