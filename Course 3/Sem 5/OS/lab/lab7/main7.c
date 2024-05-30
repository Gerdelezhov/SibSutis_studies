#include <stdio.h>
#include <dlfcn.h>
#include "student.h"
#include <unistd.h>

int main() {
    void *lib_handle;
    struct Student* (*createStudent)(char[], int, float);
    void (*insertStudent)(struct Student*);
    void (*displayStudents)();
    void (*deleteStudent)(int);
    void (*serializeStudents)(const char *);

    // Загрузка библиотеки
    lib_handle = dlopen("./libstudents.so", RTLD_LAZY);
    if (!lib_handle) {
        fprintf(stderr, "Ошибка при загрузке библиотеки: %s\n", dlerror());
        return 1;
    }

    // Получение указателей на функции из библиотеки
    createStudent = dlsym(lib_handle, "createStudent");
    insertStudent = dlsym(lib_handle, "insertStudent");
    displayStudents = dlsym(lib_handle, "displayStudents");
    deleteStudent = dlsym(lib_handle, "deleteStudent");
    serializeStudents = dlsym(lib_handle, "serializeStudents");

    if (createStudent && insertStudent && displayStudents && deleteStudent && serializeStudents) {
        struct Student* student1 = createStudent("Иван", 101, 85.5);
        struct Student* student2 = createStudent("Мария", 102, 92.0);
        struct Student* student3 = createStudent("Пётр", 103, 78.2);

        insertStudent(student1);
        insertStudent(student2);
        insertStudent(student3);

        displayStudents();
        deleteStudent(102);
        displayStudents();

        serializeStudents("journal.dat");
    } else {
        fprintf(stderr, "Ошибка при получении указателей на функции: %s\n", dlerror());
        return 1;
    }

    printf("\nPID %d\n", getpid());
    int flag_1, flag_2;
    scanf("%d", &flag_1);

    // Закрытие библиотеки
    dlclose(lib_handle);

    scanf("%d", &flag_2);

    return 0;
}
