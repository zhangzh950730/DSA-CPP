//
// Created by 张之豪 on 2021/12/6.
//

#include <cstdio>

#ifndef DSA_CPP_GRAPH_H
#define DSA_CPP_GRAPH_H

#define  MAX_VERTEX_NUM 100
typedef struct {

    int vexnum;
} Graph;
#endif //DSA_CPP_GRAPH_H

void visit(int v);

int FirstNeighbor(Graph G, int v);

int NextNeighbor(Graph G, int v, int w);
