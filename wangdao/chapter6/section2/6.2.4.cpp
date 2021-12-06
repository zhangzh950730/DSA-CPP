//
// Created by 张之豪 on 2021/12/6.
//

#include "../ALGraph.h"

void Convert(ALGraph &G, int *arcs[], int n) {
    for (int i = 0; i < n; ++i) {
        ArcNode *p = G.vertices[i].first;
        while (p != nullptr) {
            arcs[i][p->adjvex] = 1;
            p = p->next;
        }
    }
}
