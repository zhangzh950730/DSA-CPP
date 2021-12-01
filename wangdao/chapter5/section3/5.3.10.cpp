//
// Created by 张之豪 on 2021/11/30.
//
#include <cstdlib>
#include "../BiTNode.h"

int i = 1;

ElemType PreNode(BiTree b, int k) {
    if (b == NULL) {
        return '#';
    }
    if (i == k) {
        return b->data;
    }
    i++;
    ElemType ch = PreNode(b->lChild, k);
    if (ch != '#') return ch;
    ch = PreNode(b->rChild, k);
    return ch;
}

