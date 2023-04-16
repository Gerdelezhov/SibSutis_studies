#include "strings/strings.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PATH 260

void input(char* path, char* delim)
{
    printf("delim: ");
    scanf("%s", delim);
    printf("path: ");
    scanf("%s", path);
    printf("\n");
}

int check(char* path, char* delim)
{
    char* buf_path = malloc(sizeof(char) * slen(path) + 2);
    scat(buf_path, path);
    buf_path[slen(buf_path)] = *delim;
    buf_path[slen(buf_path)] = '\0';

    //printf("Ведённая строка разбита на:\n");
    char* str_tmp;
    for (str_tmp = stok(buf_path, delim); str_tmp;
         str_tmp = stok(NULL, delim)) {
        //printf("%s\n", str_tmp);

        if (slen(path) >= MAX_PATH) { // len
            return 3;
        }

        char* win_slah = sstr(str_tmp, ":\\"); // windows
        char* lin_slah = sstr(str_tmp, "\\");

        /*if (win_slah == 0) {
            return 1;
        }*/

        if (lin_slah) {
            if (!isalpha(str_tmp[0]) && str_tmp[0] != '\\') {
                return 1;
            }
            if (sspn(str_tmp, "*?<\">,/|")) {
                return 1;
            }
        }

        if ((win_slah - str_tmp == 1) || (win_slah - str_tmp == 2)) {
            if (isalpha(str_tmp[0]) && str_tmp[1] == ':') {
                if (sspn(str_tmp, "*?<\">,/|")) {
                    return 1;
                }
            }
            if (sspn(str_tmp, "*?<\">,/|")) {
                return 1;
            }
            if (win_slah - str_tmp == 1) {
                if (str_tmp[0] > 90) {
                    return 1;
                }
            } else if (win_slah - str_tmp == 2) {
                if (str_tmp[0] > 90
                    || str_tmp[1] > 90) { //проверка на заглавные буквы
                    return 1;
                }
            }
        } else if (((win_slah = sstr(str_tmp, "/")) - str_tmp) == 0) {
            if (sspn(str_tmp, "*?:\\<\">,|")) {
                return 2;
            }
        }
    }
    return 0;
}

// 0 - good, 1 - trable windows, 2 - trable linux, 3 - problam with len of
// path
void output(int n)
{
    switch (n) {
    case 0:
        //
        break;
    case 1:
        printf("Problem in the way Windows.\n");
        break;
    case 2:
        printf("Problem in the way Linux.\n");
        break;
    case 3:
        printf("Length too long.\n");
        break;
    }
}

char* process(char* path, char* delim)
{
    char* buf_path = malloc(sizeof(char) * slen(path) + 2);
    scpy(buf_path, path);
    buf_path[slen(path)] = *delim;
    buf_path[slen(path) + 1] = '\0';
    char* res = malloc(slen(path)); //итоговая строка
    char* tmp;
    for (tmp = stok(buf_path, delim); tmp;
         tmp = stok(NULL, delim)) { //делим на подстроки весь путь
        if (slen(res)) {
            scat(res, delim);
        }
        char* buf = malloc(sizeof(char) * slen(tmp) + 2); //хрaнит подстроку
        scpy(buf, tmp);
        buf[slen(buf)] = '\\';
        buf[slen(buf) + 1] = 0;
        char* ttmp;
        int a = 0, b = 0;
        if ((ttmp = sstr(buf, ":\\"))) {
            a = 1;
        } else if ((ttmp = sstr(buf, "\\"))) {
            b = 1;
        }
        if (a || b) {
            int c = 1; //для прав работы сток
            char* tr = malloc(
                    sizeof(char) * (slen(buf) + 11)); //итоговая подстрока
            if (a) {
                scat(tr, "/cygdrive/");
                int n = ttmp - buf;
                c = 3;
                if (n == 1) { //если одна буква в пути
                    tr[10] = buf[0] + 32;
                } else if (n == 2) { //если две буквы в пути
                    tr[10] = buf[0] + 32;
                    tr[11] = buf[1] + 32;
                }
            } else if (b) {
                scat(tr, "/cygdrive");
            }
            char* tmp_t;
            char* tmp_lt = save_static_char();
            for (tmp_t = stok(buf + c, "\\"); tmp_t;
                 tmp_t = stok(NULL, "\\")) { //добавление в итоговую подстроку
                                             //путей исходного пути
                scat(tr, "/");
                scat(tr, tmp_t);
            }
            new_static_char(tmp_lt);
            res = realloc(res, slen(res) + slen(tr));
            scat(res, tr);
        } else {
            res = realloc(res, slen(res) + slen(tmp));
            scat(res, tmp);
        }
    }
    res[slen(res)] = 0; //конец итоговой строки
    return res;
}

int main()
{
    system("clear");

    char* path = malloc(sizeof(char) * MAX_PATH);
    char* delim = malloc(sizeof(char) * 1);

    input(path, delim);

    int t = check(path, delim);
    if (!t) {
        printf("\nПолученные пути:\n%s\n", process(path, delim));
    } else {
        output(t);
    }

    return 0;
}
