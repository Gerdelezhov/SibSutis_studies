//Проверка строк на совпадение с учетом регистра
#include <stdio.h>
#include <stdlib.h>

int scmp(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            if (str1[i] > str2[i])
                return 1;
            else if (str2[i] > str1[i])
                return -1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    char str1[] = "aboba";
    char str2[] = "abobA";
    int a = scmp(str1, str2);
    printf("%d\n", a);

    return 0;
}