//Поиск подстроки в строке.
#include <stdio.h>
#include <stdlib.h>

void search(char *str, char *search, int *from, int *to, int search_len)
{
    int j = 0, k = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == search[j]) {
            k++;
            if (k == search_len) {
                *from = i - j;
                *to = i; 
            }
            j++;
        } else {
            j = 0;
            k = 0;
        }
    }
}

int main()
{
    char str[] = "abordnyhjuiklop";
    int a = 0, b = 0;
    search(str, "dnyhju", &a, &b, 6);
    printf("%d %d\n", a, b);

    return 0;
}