//
// Created by 张之豪 on 2021/12/6.
//
#include "../ALGraph.h"

int visited[MaxVertexNum];

void print(int *pInt) {

}

void FindPath(ALGraph G, int i, int j, int path[], int d) {
    int w;
    ArcNode *p;
    d++;
    path[d] = i;
    visited[i] = 1;
    if (i == j) print(path);
    p = G.vertices[i].first;
    while (p != nullptr) {
        w = p->adjvex;
        if (visited[w] == 0) {
            FindPath(G, w, j, path, d);
        }
        p = p->next;
    }
    visited[i] = 0;
}