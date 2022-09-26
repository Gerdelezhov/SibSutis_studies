//Проверка строк на совпадение без учета регистра.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int scmp(const char *str1, const char *str2)
{
    for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
        char s1 = str1[i], s2 = str2[i];
        if (str1[i] >= 'a' && str1[i] <= 'z') s1 = str1[i] - 32;
        if (str2[i] >= 'a' && str2[i] <= 'z') s2 = str2[i] - 32;
        printf("%c %c\n", s1, s2);
        if (s1 != s2) {
            if (s1 > s2)
                return 1;
            else if (s2 > s1)
                return -1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    char str1[] = "AbObaS";
    char str2[] = "aBobAs";
    int a = scmp(str1, str2);
    printf("%d\n", a);

    return 0;
}