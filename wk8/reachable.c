#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Set.h"

void dfs(Graph g, Vertex v, Set visited) {
    if (SetContains(visited, v)) return;

    SetInsert(visited, v);

    for (Vertex w = 0; w < GraphNumVertices(g); w++) {
        if (GraphIsAdjacent(g, v, w)) {
            dfs(g, w, visited);
        }
    }
}

Set reachable(Graph g, Vertex src) {
    Set visited = SetNew();

    dfs(g, src, visited);

    return visited;
}
