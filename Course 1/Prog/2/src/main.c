#include "IntVector.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Cоздаем массив v ёмкостью 7 с помощью функции int_vector_new:\n");
    IntVector* v = int_vector_new(7);
    printf("vector v:\ndata: %p\nsize: %ld\ncapacity: %ld\n",
           v->data,
           v->size,
           v->capacity);

    printf("-----\nЗаполняем массив, используя функцию int_vector_get_capacity "
           "что "
           "бы "
           "узнать его ёмкость\nи функцию int_vector_push_back что бы добавить "
           "элемент в конец массива.\n");
    for (int i = 0; i < int_vector_get_capacity(v); i++) {
        int_vector_push_back(v, (rand() % 50 + 1));
    }
    printf("Выводим массив, используя функцию int_vector_get_size что бы "
           "узнать "
           "его размер\nи функцию int_vector_get_item что бы получать элементы "
           "массива.\n");
    for (int i = 0; i < int_vector_get_size(v); i++) {
        printf("%d = %d\t", i, int_vector_get_item(v, i));
    }

    printf("\n-----\nИзменим третий элемент массива на 999 с помощью фунции "
           "int_vector_set_item\nи добавим в последниий элемент массива 15 с "
           "помощью "
           "функции int_vector_push_back:\n");
    int_vector_set_item(v, 2, 999);
    int_vector_push_back(v, 15);
    printf("vector v:\ndata: %p\nsize: %ld\ncapacity: %ld\n",
           v->data,
           v->size,
           v->capacity);
    for (int i = 0; i < int_vector_get_size(v); i++) {
        printf("%d = %d\t", i, int_vector_get_item(v, i));
    }
    printf("\nТак как изначальной ёмкости (7) не хватило для добавления нового "
           "элемента \nона удвоилась");

    printf("\n-----\nПопробуем уменьшить емкость ёмкость массива до 5 с "
           "помощью "
           "функции int_vector_reserve\n");
    int_vector_reserve(v, 5);
    printf("vector v:\ndata: %p\nsize: %ld\ncapacity: %ld\n",
           v->data,
           v->size,
           v->capacity);
    printf("Так как ёмкость меньше исходной ничего не произошло.");

    printf("\n-----\nУвеличим ёмкость массива до 15 с помощью функции "
           "int_vector_reserve");
    int_vector_reserve(v, 15);
    printf("\nvector v:\ndata: %p\nsize: %ld\ncapacity: %ld\n",
           v->data,
           v->size,
           v->capacity);

    printf("-----\nУменьшим ёмкость массива до его размера с помощью функции "
           "int_vector_shrink_to_fit");
    int_vector_shrink_to_fit(v);
    printf("\nvector v:\ndata: %p\nsize: %ld\ncapacity: %ld\n",
           v->data,
           v->size,
           v->capacity);

    printf("-----\nУвеличим ёмкость массива до 15 после чего\nувеличим размер "
           "до 11 "
           "с помощью функции int_vector_resize:");
    int_vector_reserve(v, 15);
    int_vector_resize(v, 11);
    printf("\nvector v:\ndata: %p\nsize: %ld\ncapacity: %ld\n",
           v->data,
           v->size,
           v->capacity);

    printf("-----\nПопробуем уменьшить размер массива до 4 с помошью функции "
           "int_vector_resize");
    int_vector_resize(v, 4);
    printf("\nvector v:\ndata: %p\nsize: %ld\ncapacity: %ld\n",
           v->data,
           v->size,
           v->capacity);
    printf("Размер массива уменьшился, но память не перевыделилась, \nзначит "
           "функция отработала правильно");

    printf("\n-----\nСоздаем копию массива v - массив t с помощью функции "
           "int_vector_copy");
    printf("\nvector v:\ndata: %p\nsize: %ld\ncapacity: %ld\n",
           v->data,
           v->size,
           v->capacity);
    printf("элементы вектора v: ");
    for (int i = 0; i < int_vector_get_size(v); i++) {
        printf("%d = %d  ", i, int_vector_get_item(v, i));
    }
    IntVector* t = int_vector_copy(v);
    printf("\n\nvector t: \ndata: %p\nsize: %ld\ncapacity: %ld\n",
           t->data,
           t->size,
           t->capacity);
    printf("элементы вектора t: ");
    for (int i = 0; i < int_vector_get_size(t); i++) {
        printf("%d = %d  ", i, int_vector_get_item(t, i));
    }

    printf("\n-----\nЗатем освобождаем паямять выделенную под массив t с "
           "помощью "
           "функции int_vector_free\n");
    int_vector_free(t);
    printf("vector t: \ndata: %p\nsize: %ld\ncapacity: %ld\n",
           t->data,
           t->size,
           t->capacity);
    return 0;
}
