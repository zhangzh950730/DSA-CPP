//
// Created by 张之豪 on 2021/11/30.
//
#include "../BiTNode.h"

void swap(BiTree b) {
    if (b) {
        swap(b->lChild);
        swap(b->rChild);
        BiTree temp = b->lChild;
        b->lChild = b->rChild;
        b->rChild = temp;
    }
}
