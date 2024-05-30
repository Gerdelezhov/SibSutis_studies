#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstdlib>
#include <vector>

#include "constants.h"

struct client {
    int socketHandle;
    int id;
    char nickname[MAX_NICKNAME_SIZE + 1]{'\0'};
};

std::vector<client> clients;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void sendToAll(char msg[BUFFER_SIZE]) {
    pthread_mutex_lock(&mutex);
    for (unsigned int i = 0; i < clients.size(); i++) {
        if (send(clients[i].socketHandle, msg, BUFFER_SIZE, 0) < 0)
            fprintf(
                stderr,
                "[ERROR]\tНе удалось отправить сообщение пользователю \"%s\"\n",
                clients[i].nickname);
    }
    pthread_mutex_unlock(&mutex);
}

void removeClient(int id) {
    int index = -1;

    pthread_mutex_lock(&mutex);
    for (unsigned int i = 0; i < clients.size(); i++) {
        if (clients[i].id == id) index = (int)i;
    }
    if (index != -1) {
        clients.erase(clients.begin() + index);
    } else {
        fprintf(stderr, "[ERROR]\tНе удалось удалить клиента из вектора\n");
    }
    pthread_mutex_unlock(&mutex);
}

void* handleClient(void* clientSocketHandlePtr) {
    int clientSocketHandle = *(int*)clientSocketHandlePtr;
    free(clientSocketHandlePtr);

    char name[MAX_NICKNAME_SIZE + 1];
    char msg[MSG_SIZE + 1];
    char buffer[BUFFER_SIZE];

    struct client* newClient = new client();
    newClient->id = clients.size();
    newClient->socketHandle = clientSocketHandle;

    memset(buffer, 0, sizeof(buffer));
    int bytesRecv;

    if (recv(clientSocketHandle, name, sizeof(name), 0) < 0) {
        delete newClient;
        return nullptr;
    } else {
        strcpy(newClient->nickname, name);
        fprintf(stdout,
                "[INFO]\tПрисоединился новый пользователь! Ему был присвоен "
                "идентификатор #%d, его никнейм: %s!\n",
                newClient->id, newClient->nickname);
        send(newClient->socketHandle, "[SERVER]\tДобро пожаловать в чат!",
             sizeof("[SERVER]\tДобро пожаловать в чат!"), 0);

        buffer[0] = '\0';
        strcat(buffer, "[SERVER]\t");
        strcat(buffer, newClient->nickname);
        strcat(buffer, "Присоединился к чату");
        sendToAll(buffer);
        pthread_mutex_lock(&mutex);
        clients.push_back(*newClient);
        pthread_mutex_unlock(&mutex);
    }

    while (true) {
        buffer[0] = '\0';
        bytesRecv = recv(clientSocketHandle, msg, sizeof(msg), 0);

        if (bytesRecv == 0) {
            fprintf(stdout,
                    "[INFO]\tПользователь #%d(%s) отсоединился от сервера!\n",
                    newClient->id, newClient->nickname);
            buffer[0] = '\0';
            strcat(buffer, "[SERVER]\t");
            strcat(buffer, newClient->nickname);
            strcat(buffer, " покинул чат...");
            sendToAll(buffer);

            close(clientSocketHandle);
            removeClient(newClient->id);
            break;
        } else if (bytesRecv < 0) {
            fprintf(stderr,
                    "[ERROR]\tОшибка при получении сообщения от клиента с "
                    "идентификатором #%d!\n",
                    newClient->id);
        } else {
            strcat(buffer, newClient->nickname);
            strcat(buffer, ">  ");
            strcat(buffer, msg);
            fprintf(stdout,
                    "[INFO]\tПользователь #%d(%s) отправил сообщение:\"%s\"\n",
                    newClient->id, newClient->nickname, msg);
            sendToAll(buffer);
        }
    }
    return nullptr;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "./server [port]\nНапример, \"./server 2007\"\n");
        return 1;
    }
    char* port = argv[1];

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        fprintf(stderr, "[Error]\tНе удалось создать serverSocket\n");
        return -1;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(strtol(port, nullptr, 0));

    if (bind(serverSocket, (struct sockaddr*)&serverAddr,
             sizeof(struct sockaddr_in)) < 0) {
        fprintf(stderr, "[Error]\tНе удалось присвоить сокету имя\n");
        return 1;
    }

    listen(serverSocket, SOMAXCONN);
    fprintf(stderr, "[INFO]\tСервер запущен!\n");

    while (true) {
        int* clientSocketHandlePtr = (int*)malloc(sizeof(int));
        *clientSocketHandlePtr = accept(serverSocket, nullptr, nullptr);
        if (*clientSocketHandlePtr < 0) {
            fprintf(stderr,
                    "[ERROR]\tОшибка при установлении соединения с клиентом\n");
            free(clientSocketHandlePtr);
        } else {
            pthread_t thread;
            if (pthread_create(&thread, NULL, handleClient,
                               (void*)clientSocketHandlePtr) != 0) {
                fprintf(stderr,
                        "[ERROR]\tОшибка при создании потока для клиента\n");
                free(clientSocketHandlePtr);
            } else {
                pthread_detach(thread);
            }
        }
    }

    return 0;
}
