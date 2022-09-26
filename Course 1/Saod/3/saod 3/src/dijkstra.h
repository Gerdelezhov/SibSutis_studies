#pragma once
#include "graph.h"
#include <sys/time.h>

int getrand(int min, int max);
double wtime();
void shortest_path_dijkstra(graph *g, int src, int *d, int *prev);
void search_shortest_path(int *prev, int src, int dst, int *pathlen, int *path);
