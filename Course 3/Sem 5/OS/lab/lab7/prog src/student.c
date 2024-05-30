#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student* createStudent(char name[], int roll_number, float grade) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent != NULL) {
        strncpy(newStudent->name, name, sizeof(newStudent->name));
        newStudent->roll_number = roll_number;
        newStudent->grade = grade;
        newStudent->next = NULL;
    }
    return newStudent;
}
