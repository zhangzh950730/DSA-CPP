//
// Created by 张之豪 on 2021/12/6.
//
#include "Graph.h"

bool visited[MAX_VERTEX_NUM];

void DFS(Graph G, int v) {
    visit(v);
    visited[v] = true;
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
}

void DFSTraverse(Graph G) {
    for (int v = 0; v < G.vexnum; ++v) {
        visited[v] = false;
    }
    for (int v = 0; v < G.vexnum; ++v) {
        if (!visited[v]) {
            DFS(G, v);
        }
    }
}
