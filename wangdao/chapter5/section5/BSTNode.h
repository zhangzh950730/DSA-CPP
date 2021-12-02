//
// Created by 张之豪 on 2021/12/1.
//
#include "../../Common.h"


typedef struct BSTNode {
    ElemType data;
    int count;
    struct BSTNode *lChild, *rChild;
} BSTNode, *BiTree;