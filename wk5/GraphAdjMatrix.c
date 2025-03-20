#include "Graph.h"

struct graph {
    int nV;
    bool **adjMatrix;
};

Graph GraphNew(int nV) {
    Graph g = malloc(sizeof(struct graph));
    g->nV = nV;

    g->adjMatrix = malloc(nV * sizeof(bool *));
    for (int i = 0; i < nV; i++) {
        g->adjMatrix[i] = calloc(nV, sizeof(bool));
    }

    // g->adjMatrix[1][2] = true;

    return g;
}
