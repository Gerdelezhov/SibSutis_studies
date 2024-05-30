#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child_pid1, child_pid2;

    child_pid1 = fork();

    if (child_pid1 < 0)
    {
        perror("Ошибка при создании первого дочернего процесса");
        exit(EXIT_FAILURE);
    }
    else if (child_pid1 == 0)
    {
        printf("Это первый дочерний процесс (PID %d)\n", getpid());
        execl("./1", "первая_программа", NULL);
        perror("Ошибка при запуске первой программы");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Это родительский процесс (PID %d)\n", getpid());
    }

    child_pid2 = fork();

    if (child_pid2 < 0)
    {
        perror("Ошибка при создании второго дочернего процесса");
        exit(EXIT_FAILURE);
    }
    else if (child_pid2 == 0)
    {
        printf("Это второй дочерний процесс (PID %d)\n", getpid());
        execl("./2", "вторая_программа", NULL);
        perror("Ошибка при запуске второй программы");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Это родительский процесс (PID %d)\n", getpid());
    }

    wait(NULL);
    wait(NULL);

    printf("Родительский процесс завершил выполнение\n");

    return 0;
}
