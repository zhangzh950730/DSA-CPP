//
// Created by 张之豪 on 2021/12/6.
//
#include "../Graph.h"

void DFS(Graph &G, int v, int &Vnum, int &Enum, int visited[]) {
    visited[v] = true, Vnum++;
    int w = FirstNeighbor(G, v);
    while (w != -1) {
        Enum++;
        if (!visited[w]) {
            DFS(G, w, Vnum, Enum, visited);
        }
        w = NextNeighbor(G, v, w);
    }
}

bool isTree(Graph &G) {
    int visited[MAX_VERTEX_NUM];
    for (int i = 0; i < G.vexnum; ++i) {
        visited[i] = false;
    }
    int Vnum = 0, Enum = 0;
    DFS(G, 1, Vnum, Enum, visited);
    if (Vnum == G.vexnum && Enum == 2 * (G.vexnum - 1)) {
        return true;
    } else return false;
}