//
// Created by 张之豪 on 2021/11/30.
//
#include "../BiTNode.h"

int DsonNodes(BiTree b) {
    if (!b) {
        return 0;
    } else if (b->lChild && b->rChild) {
        return DsonNodes(b->lChild) + DsonNodes(b->rChild) + 1;
    } else {
        return DsonNodes(b->lChild) + DsonNodes(b->rChild);
    }
}
