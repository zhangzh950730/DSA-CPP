//
// Created by 张之豪 on 2021/12/2.
//
#include "BSTNode.h"

int level(BiTree bt, BSTNode *p) {
    int n = 0;
    BiTree t = bt;
    if (bt != nullptr) {
        n++;
        while (t->data != p->data) {
            if (p->data < t->data) {
                t = t->lChild;
            } else {
                t = t->rChild;
            }
            n++;
        }
    }
    return n;
}
