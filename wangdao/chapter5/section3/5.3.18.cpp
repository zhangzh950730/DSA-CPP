//
// Created by 张之豪 on 2021/12/1.
//

#include "../BiThrTree.h"

BiThrTree InPostPre(BiThrTree t, BiThrTree p) {
    BiThrTree q;
    if (p->rtag == 0) {
        q = p->rChild;
    } else if (p->ltag == 0) {
        q = p->lChild;
    } else if (p->lChild == nullptr) {
        q = nullptr;
    } else {
        while (p->ltag == 1 && p->lChild != nullptr) {
            p = p->lChild;
        }
        if (p->ltag == 0) q = p->lChild;
        else q = nullptr;
    }
    return q;
}