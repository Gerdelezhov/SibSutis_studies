#include <stdlib.h>
#include "student.h"
#include "list.h"

int main() {
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
    return 0;
}
