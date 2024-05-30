#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

char sh[6];
int turn = 0;
int interested[2] = {0, 0};

void lock(int self) {
    interested[self] = 1;
    turn = 1 - self;

    while (turn == 1 - self && interested[1 - self] == 1)
        ; // Ожидаем освобождения ресурса
}

void unlock(int self) {
    interested[self] = 0;
}

void* Thread(void* pParams) {
    int counter = 0;
    int id = *((int*)pParams);
    while (1) {
        lock(id);

        if (counter % 2) {
            sh[0] = 'H'; sh[1] = 'e'; sh[2] = 'l'; sh[3] = 'l'; sh[4] = 'o'; sh[5] = '\0';
        } else {
            sh[0] = 'B'; sh[1] = 'y'; sh[2] = 'e'; sh[3] = '_'; sh[4] = 'u'; sh[5] = '\0';
        }
        counter++;

        unlock(id);

        usleep(500000);
    }
    return NULL;
}

int main() {
    pthread_t thread_id[2];
    int ids[2] = {0, 1};
    pthread_create(&thread_id[0], NULL, &Thread, &ids[0]);
    pthread_create(&thread_id[1], NULL, &Thread, &ids[1]);

    while (1) {
        printf("%s\n", sh);
        usleep(100000);
    }

    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);
    return 0;
}
