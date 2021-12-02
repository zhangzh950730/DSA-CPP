//
// Created by 张之豪 on 2021/12/2.
//

#include <cstdio>
#include "BSTNode.h"

void OupPut(BiTree bt, ElemType k) {
    if (bt == nullptr) return;
    if (bt->rChild != nullptr) {
        OupPut(bt->rChild, k);
    }
    if (bt->data >= k) {
        printf("%d", bt->data);
    }
    if (bt->lChild != nullptr) {
        OupPut(bt->lChild, k);
    }
}