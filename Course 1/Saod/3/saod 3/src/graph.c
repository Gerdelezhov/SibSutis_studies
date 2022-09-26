#include "graph.h"
#include <stdlib.h>

graph* graph_create(int nverticed)
{
    graph* g = malloc(sizeof(graph));
    if (g) {
        g->nverticed = nverticed;
        g->visited = malloc(sizeof(long long) * nverticed);
        g->m = malloc(sizeof(long long) * nverticed * nverticed);
        if (g->m) {
            graph_clear(g);
            return g;
        }
    }
    return NULL;
}

void graph_clear(graph* g)
{
    for (int i = 0; i < g->nverticed; i++) {
        g->visited[i] = 0;
        for (int j = 0; j < g->nverticed; j++) {
            g->m[i * g->nverticed + j] = 0;
        }
    }
}

void graph_free(graph* g)
{
    free(g->m);
    free(g);
}

void graph_set_edge(graph* g, int i, int j, int weight)
{
    g->m[(i - 1) * g->nverticed + (j - 1)] = weight;
    g->m[(j - 1) * g->nverticed + (i - 1)] = weight;
}

int graph_get_edge(graph* g, int i, int j)
{
    return g->m[(i - 1) * g->nverticed + (j - 1)];
}

void graph_dfs(graph* g, int v)
{
    g->visited[v - 1] = 1;
    for (int i = 0; i < g->nverticed; i++) {
        if ((g->m[(v - 1) * g->nverticed + i] > 0) && (g->visited[i] == 0)) {
            graph_dfs(g, i + 1);
        }
    }
}
