#include "dijkstra.h"
#include "graph.h"
#include "heap.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    
    //связный граф 20 вершин
    int pathlen;
    int vertex = 20;
    int v[vertex + 1][vertex + 1];

    graph* g = graph_create(vertex);
    int src = 1;
    int weight;
    int v1;
    int v2;

    for (int i = 1; i <= vertex; i++) {
        for (int j = 1; j <= vertex; j++) {
            v[i][j] = 0;
        }
    }
    for (int i = 1; i <= vertex - 1; i++) {
        for (int j = i + 1; j <= vertex; j++) {
            v[i][j] = getrand(0, 2);
        }
    }

    for (int i = 1; i <= vertex; i++) {
        for (int j = 1; j <= vertex; j++) {
            if (v[i][j] == 1) //пересечение, то дорога есть,значит строим ребро
            {
                v1 = i;
                v2 = j;
                weight = getrand(1, i + j);
                graph_set_edge(g, v1, v2, weight);
                v[i][j] = weight;
            }
        }
    }

    for (int i = 1; i <= vertex; i++) {
        for (int j = 1; j <= vertex; j++) {
            v[j][i] = v[i][j];
        }
    }
    printf(" ");
    for (int i = 1; i <= vertex; i++) {
        if (i == 1) {
            for (int b = 1; b <= vertex; b++) {
                printf("%4d", b);
            }
            printf("\n   ");
            for (int b = 1; b <= vertex; b++) {
                printf("----");
            }
            printf("\n");
        }
        for (int j = 1; j <= vertex; j++) {
            if (j == 1) {
                printf("%2d| ", i);
            }
            printf("%-4d", v[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int* prev = malloc((g->nverticed + 1) * sizeof(int));
    for (int i = 0; i < 20; i++) {
        prev[1] = 1410065407;
    }
    int* d = malloc((g->nverticed + 1) * sizeof(int));
    double time1, time2;
    time1 = wtime();
    shortest_path_dijkstra(g, src, d, prev);
    time2 = wtime();
    int path[g->nverticed];
    for (int i = 1; i < g->nverticed + 1; i++) {
        if (i != src) {
            search_shortest_path(prev, src, i, &pathlen, path);
            printf("\nИз |%d| в |%-2d|, Длина пути = %2d, ", src, i, pathlen);
            printf("Мин. путь: ");
            for (int j = 1; j <= pathlen; j++) {
                if (j == pathlen)
                    printf("%d", path[j]);
                else
                    printf("%d -> ", path[j]);
            }
        }
    }
    printf("\nВремя %.6f", time2 - time1);
/*
    //граф решетка 100х100
    
        int pathlen2;
        int vertex2 = 10000;
        int size = sqrt(vertex2);
        int sizearr = vertex2 + 1;
        // int ver[vertex2 + 1][vertex2 + 1];
        int** ver = (int**)malloc(sizearr * sizeof(int*));
        int src2 = 1;

        graph* g2 = graph_create(vertex2);

        int weight2;
        int v12;
        int v22;

        for (int i = 1; i <= vertex2; i++) {
            ver[i] = (int*)malloc(sizearr * sizeof(int));
            for (int j = 1; j <= vertex2; j++) {
                ver[i][j] = 0;
            }
        }

        for (int i = 1; i <= vertex2 - size; i++) {
            for (int j = 1; j <= vertex2; j++) {
                if (i + size == j)
                    ver[i][j] = 1;
            }
        }

        for (int i = 1; i <= vertex2 - (size - (size - 1)); i++) {
            for (int j = 1; j <= vertex2; j++) {
                if (i + (size - (size - 1)) == j)
                    ver[i][j] = 1;
            }
        }

        for (int i = size; i <= vertex2 - size; i += size) {
            for (int j = size - 1; j <= vertex2 - (size - 1); j += 1) {
                if (i + size == j + (size - 1))
                    ver[i]
                       [j] = 0;
            }
        }

        if (vertex2 <= 25) {
            for (int i = 1; i <= vertex2; i++) {
                for (int j = 1; j <= vertex2; j++) {
                    ver[j][i] = ver[i][j];
                    printf("%3d", ver[i][j]);
                }
                printf("\n");
            }
        }
        printf("\n");

        for (int i = 1; i <= vertex2; i++) {
            for (int j = 1; j <= vertex2; j++) {
                if (ver[i][j] == 1) {
                    v12 = i;
                    v22 = j;
                    weight2 = getrand(1, i + j);
                    graph_set_edge(g2, v12, v22, weight2);
                }
            }
        }

        double time1, time2;
        int* d = malloc((g2->nverticed + 1) * sizeof(int));
        if (d == NULL) {
            free(d);
            return -1;
        }
        int* prev = malloc((g2->nverticed + 1) * sizeof(int));
        if (prev == NULL) {
            free(prev);
            return -1;
        }
        time1 = wtime();
        shortest_path_dijkstra(g2, src2, d, prev);
        time2 = wtime();

        int path[g2->nverticed];
        for (int i = 1; i < g2->nverticed + 1; i++) {
            if (i != src2) {
                search_shortest_path(prev, src2, i, &pathlen2, path);
                printf("\n\nИз |%d| в |%d|, Длина пути = %d, ", src2, i,
       pathlen2); printf("Мин. путь: "); for (int j = 1; j <= pathlen2; j++) { if
       (j == pathlen2) printf("%d", path[j]); else printf("%d -> ", path[j]);
                }
            }
        }
        printf("\nВремя %.6f\n", time2 - time1);
        for (int i = 1; i <= vertex2; i++) // цикл по строкам
            free(ver[i]); // освобождение памяти под строку
        free(ver);
        graph_free(g2);
        free(d);
        free(prev);*/
    printf("\n");
    return 0;
}