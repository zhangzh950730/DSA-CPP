//
// Created by 张之豪 on 2021/12/1.
//
#include "../../Common.h"

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lChild, *rChild;
    int ltag, rtag;
} BiTNode, *BiThrTree;
