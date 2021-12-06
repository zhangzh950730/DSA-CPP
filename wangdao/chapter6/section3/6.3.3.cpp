//
// Created by 张之豪 on 2021/12/6.
//
#include "Graph.h"
#include "stack"

using namespace std;

void DFS_Non_RC(Graph &G, int v) {
    int w;
    stack<int> S;
    bool visited[MAX_VERTEX_NUM];
    for (int i = 0; i < G.vexnum; ++i) {
        visited[i] = false;
    }
    S.push(v), visited[v] = true;
    while (!S.empty()) {
        v = S.top();
        S.pop();
        visit(v);
        for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            if (!visited[w]) {
                S.push(w);
                visited[w] = true;
            }
        }
    }
}