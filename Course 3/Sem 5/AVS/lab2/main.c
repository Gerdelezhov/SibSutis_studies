#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(int signo) {
    printf("Приняли сигнал SIGINT. Завершение программы.\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, sigint_handler);

    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (file) {
            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), file)) {
                printf("%s", buffer);
            }
            fclose(file);
        } else {
            printf("Не удалось открыть файл.\n");
        }
    } else {
        printf("Не передан путь к файлу как аргумент командной строки.\n");
    }

    while (1) {
    }

    return 0;
}
