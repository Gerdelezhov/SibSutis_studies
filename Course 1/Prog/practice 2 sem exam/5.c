//Перевод символов строки в число.
#include <stdio.h>
#include <stdlib.h>

int str_to_int(char *str, int a)
{
    for (int i = 0; str[i] != '\0'; i++) {
        a = (a * 10) + (str[i] - '0');
    }

    return a;
}

int main(int argc, char const *argv[])
{
    int a = 0;
    char str[] = "1488";
    int b = str_to_int(str, a);
    printf("%d\n", b);

    return 0;
}