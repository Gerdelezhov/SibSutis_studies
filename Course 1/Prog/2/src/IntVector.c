#include "IntVector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

IntVector* int_vector_new(size_t initial_capacity)
{
    IntVector* v = malloc(sizeof(IntVector));
    if (!v) {
        return NULL;
    }

    v->data = malloc(sizeof(int) * initial_capacity);
    if (!v->data) {
        free(v);
        return NULL;
    }

    v->size = 0;
    v->capacity = initial_capacity;
    return v;
}

IntVector* int_vector_copy(const IntVector* v)
{
    if (v == NULL)
        return NULL;
    IntVector* t = malloc(sizeof(IntVector));
    if (t == NULL)
        return NULL;
    t->data = malloc(v->capacity * sizeof(int));
    if (t->data == NULL) {
        free(t);
        return NULL;
    }

    memcpy(t->data, v->data, sizeof(int) * v->capacity);
    t->size = v->size;
    t->capacity = v->capacity;
    return t;
}

void int_vector_free(IntVector* v)
{
    if (v != NULL) {
        return;
        free(v->data);
        free(v);
    }
}

int int_vector_get_item(const IntVector* v, size_t index)
{
    return v->data[index];
}

void int_vector_set_item(IntVector* v, size_t index, int item)
{
    if (index <= v->capacity)
        v->data[index] = item;
}

size_t int_vector_get_size(const IntVector* v)
{
    return v->size;
}

size_t int_vector_get_capacity(const IntVector* v)
{
    return v->capacity;
}

int int_vector_push_back(IntVector* v, int item)
{
    if (v->size < v->capacity) {
        v->data[v->size] = item;
        v->size++;
    } else {
        int* t = realloc(v->data, v->capacity * 2 * sizeof(int));
        if (t == NULL) {
            return -1;
        }
        v->capacity = v->capacity * 2;
        v->data = t;
        v->data[v->size] = item;
        v->size++;
    }
    return 0;
}

void int_vector_pop_back(IntVector* v)
{
    if (v->size != 0) {
        v->size--;
    }
}

int int_vector_shrink_to_fit(IntVector* v)
{
    if (v->size < v->capacity) {
        v->capacity = v->size;
        int* t = realloc(v->data, v->size * sizeof(int));
        if (t == NULL)
            return -1;
        v->data = t;
        return 0;
    }
    return -1;
}

int int_vector_resize(IntVector* v, size_t new_size)
{
    if (new_size <= v->size) {
        v->size = new_size;
    }
    if (new_size == v->size)
        return 0;
    if (new_size > v->size) {
        if (v->capacity < new_size) {
            int_vector_reserve(v, new_size);
        }
        int* t = realloc(v->data, new_size * sizeof(int));
        if (t == NULL)
            return -1;
        v->data = t;
        for (int i = new_size - v->size; i < new_size; i++) {
            v->data[i] = 0;
        }
        v->size = new_size;
    }
    return 0;
}

int int_vector_reserve(IntVector* v, size_t new_capacity)
{
    if (new_capacity > v->capacity) {
        int* t = realloc(v->data, new_capacity * sizeof(int));
        if (t == NULL)
            return -1;
        v->data = t;
        v->capacity = new_capacity;
        return 0;
    }
    return -1;
}
