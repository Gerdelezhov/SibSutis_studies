// list.h
#ifndef LIST_H
#define LIST_H

#include "student.h"

void insertStudent(struct Student* newStudent);
void deleteStudent(int roll_number);
void displayStudents();
void serializeStudents(const char *filename);

#endif
