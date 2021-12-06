//
// Created by 张之豪 on 2021/12/6.
//
#include "../ALGraph.h"
#include "queue"

using namespace std;

int visited[MaxVertexNum];

void DFS(ALGraph G, int i, int j, bool &can_reach) {
    if (i == j) {
        can_reach = true;
        return;
    }
    visited[i] = 1;
    for (int p = FirstNeighbor(G, i); p >= 0; p = NextNeighbor(G, i, p)) {
        if (!visited[p] && !can_reach) {
            DFS(G, p, j, can_reach);
        }
    }
}

int BFS(ALGraph G, int i, int j) {
    queue<int> Q;
    Q.push(i);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        if (u == j)return 1;
        for (int p = FirstNeighbor(G, u); p >= 0; p = NextNeighbor(G, u, p)) {
            if (p == j) return 1;
            if (!visited[p]) {
                Q.push(p);
                visited[p] = 1;
            }
        }
    }
    return 0;
}
