//
// Created by 张之豪 on 2021/12/7.
//
#include "../Graph.h"
#include "../ALGraph.h"
#include "stack"

using namespace std;
int indegree[MAX_VERTEX_NUM];

bool TopologicalSort(ALGraph G) {
    stack<int> S;
    int i;
    for (i = 0; i < G.vexnum; ++i) {
        if (indegree[i] == 0) {
            S.push(i);
        }
    }
    int count = 0;
    while (!S.empty()) {
        i = S.top();
        S.pop();
        printf("%d,%d\n", count++, i);
        for (ArcNode *p = G.vertices[i].first; p != nullptr; p = p->next) {
            int v = p->adjvex;
            if (!(--indegree[v])) {
                S.push(v);
            }
        }
    }
    return count == G.vexnum;
}

