#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // Включаем заголовочный файл unistd.h

int main() {
    int pid = getpid();  // Получаем идентификатор текущего процесса
    char filename[256];
    snprintf(filename, sizeof(filename), "/proc/%d/maps", pid);

    // Открываем файл /proc/PID/maps для чтения
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Не удалось открыть файл /proc/PID/maps");
        return 1;
    }

    char line[256];
    const char libraryName[] = "libstudents.so";  // Название вашей библиотеки
    int libraryFound = 0;  // Флаг для отслеживания нахождения библиотеки

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, libraryName) != NULL) {
            printf("Библиотека '%s' обнаружена в адресном диапазоне:\n%s", libraryName, line);
            libraryFound = 1;
        }
    }

    if (!libraryFound) {
        printf("Библиотека '%s' не обнаружена в адресном диапазоне.\n", libraryName);
    }
    wait(NULL);
    fclose(file);

    return 0;
}
