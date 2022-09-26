//Преобразование CamelCase в snake_case
#include <stdio.h>
#include <stdlib.h>

void camel_to_snake(char *str)
{
    char temp_ar[200];
    int g;
    for (int i = 0; str[i] != '\0'; i++) {
        g = 0;
        if (str[i] > 'A' && str[i] < 'Z') {
            temp_ar[g] = str[i] += 32;
            g++;
            for (int j = i + 1; str[j] != '\0'; j++) {
                temp_ar[g] = str[j];
                g++;
            }
            temp_ar[g] = '\0';
            str[i] = '_';
            g = 0;
            for (int j = i + 1; temp_ar[g] != '\0'; j++) {
                str[j] = temp_ar[g];
                g++;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    char str[200] = "abObUs";
    camel_to_snake(str);
    printf("%s\n", str);

    return 0;
}