// student.h
#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    char name[50];
    int roll_number;
    float grade;
    struct Student* next;
};

struct Student* createStudent(char name[], int roll_number, float grade);

#endif
