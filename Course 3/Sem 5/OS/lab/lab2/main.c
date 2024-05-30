#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для представления информации о студенте
struct Student
{
    char name[50];
    int roll_number;
    float grade;
    struct Student *next;
};

// Глобальная переменная для хранения указателя на начало списка
struct Student *head = NULL;

// Функция для вставки нового студента в начало списка
void insertStudent(char name[], int roll_number, float grade)
{
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    strncpy(newStudent->name, name, sizeof(newStudent->name));
    newStudent->roll_number = roll_number;
    newStudent->grade = grade;
    newStudent->next = head;
    head = newStudent;
    printf("Студент добавлен в журнал.\n");
}

// Функция для удаления студента по его номеру
void deleteStudent(int roll_number)
{
    struct Student *current = head;
    struct Student *prev = NULL;
    while (current != NULL)
    {
        if (current->roll_number == roll_number)
        {
            if (prev == NULL)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            printf("\nСтудент удален из журнала.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Студент с номером %d не найден.\n", roll_number);
}

// Функция для отображения списка студентов
void displayStudents()
{
    struct Student *current = head;
    if (current == NULL)
    {
        printf("\nЖурнал успеваемости пуст.\n");
    }
    else
    {
        printf("\nЖурнал успеваемости студентов:\n");
        while (current != NULL)
        {
            printf("Имя: %s, Номер: %d, Оценка: %.2f\n", current->name, current->roll_number, current->grade);
            current = current->next;
        }
    }
}

// Функция для сериализации списка студентов в файл
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
int main()
{
    insertStudent("Иван", 101, 85.5);
    insertStudent("Мария", 102, 92.0);
    insertStudent("Петр", 103, 78.2);
    displayStudents();
    deleteStudent(102);
    displayStudents();
    serializeStudents("journal.dat");
    return 0;
}
