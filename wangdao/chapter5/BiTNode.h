//
// Created by 张之豪 on 2021/11/29.
//
#include "../Common.h"

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lChild, *rChild;
} BiTNode, *BiTree;