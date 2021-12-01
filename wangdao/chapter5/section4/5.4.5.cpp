//
// Created by 张之豪 on 2021/12/1.
//

#include "../BiTNode.h"

typedef struct node {
    ElemType data;
    struct node *fch, *nsib;
} *Tree;

int Leaves(Tree t) {
    if (t == nullptr) {
        return 0;
    }
    if (t->fch == nullptr) {
        return 1 + Leaves(t->nsib);
    } else {
        return Leaves(t->fch) + Leaves(t->nsib);
    }
}