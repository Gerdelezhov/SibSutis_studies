//Преобразование snake_case в CamelCase
#include <stdio.h>
#include <stdlib.h>

void snake_to_camel(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        char temp_ar[200];
        if (str[i] == '_') {
            int g = 0;
            for (int j = i + 1; str[j] != '\0'; j++) {
                temp_ar[g] = str[j];
                g++;
            }
            temp_ar[g] = '\0';
            g = 0;
            int j;
            for (j = i; temp_ar[g] != '\0'; j++) {
                str[j] = temp_ar[g];
                g++;
            }
            str[j] = '\0';
            str[i] -= 32;
        }
    }
}

int main(int argc, char const *argv[])
{
    char str[200] = "ab_ob_us";
    snake_to_camel(str);
    printf("%s\n", str);

    return 0;
}
