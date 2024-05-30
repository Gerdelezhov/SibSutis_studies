#include "student.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct Student* head = NULL;

void insertStudent(struct Student* newStudent) {
    newStudent->next = head;
    head = newStudent;
    printf("Студент добавлен в журнал.\n");
}

void deleteStudent(int roll_number) {
    struct Student* current = head;
    struct Student* prev = NULL;
    while (current != NULL) {
        if (current->roll_number == roll_number) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Студент удален из журнала.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Студент с номером %d не найден.\n", roll_number);
}

void displayStudents() {
    struct Student* current = head;
    if (current == NULL) {
        printf("\nЖурнал успеваемости пуст.\n");
    } else {
        printf("\nЖурнал успеваемости студентов:\n");
        while (current != NULL) {
            printf("Имя: %s, Номер: %d, Оценка: %.2f\n", current->name, current->roll_number, current->grade);
            current = current->next;
        }
    }
}

void serializeStudents(const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        perror("Ошибка при открытии файла для записи");
        return;
    }
    struct Student *current = head;
    while (current != NULL)
    {
        fwrite(current, sizeof(struct Student), 1, file);
        current = current->next;
    }
    fclose(file);
    printf("Сериализация завершена.\n");
}