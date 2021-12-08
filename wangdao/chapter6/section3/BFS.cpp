//
// Created by 张之豪 on 2021/12/6.
//
#include "../Graph.h"
#include "queue"

using namespace std;

bool visited[MAX_VERTEX_NUM];
queue<int> Q;

void BFS(Graph G, int v) {
    visit(v);
    visited[v] = true;
    Q.push(v);
    while (!Q.empty()) {
        v = Q.front(), Q.pop();
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
            if (!visited[w]) {
                visit(w);
                visited[w] = true;
                Q.push(w);
            }
        }
    }

}

void BFSTraverse(Graph G) {
    for (int i = 0; i < G.vexnum; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < G.vexnum; ++i) {
        if (!visited[i]) {
            BFS(G, i);
        }
    }
}

int d[MAX_VERTEX_NUM];

void BFS_MIN_Distance(Graph G, int u) {
    for (int i = 0; i < G.vexnum; ++i) {
        d[i] = INT_MAX;
    }
    visited[u] = true, d[u] = 0;
    Q.push(u);
    while (!Q.empty()) {
        u = Q.front(), Q.pop();
        for (int w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w)) {
            if (!visited[w]) {
                visited[w] = true;
                d[w] = d[u] + 1;
                Q.push(w);
            }
        }
    }
}
