//
// Created by 张之豪 on 2021/12/2.
//

#include "BSTNode.h"

int predt = -32767;

int JudgeBST(BiTree bt) {
    int b1, b2;
    if (bt == nullptr) return 1;
    else {
        b1 = JudgeBST(bt->lChild);
        if (b1 == 0 || predt >= bt->data) {
            return 0;
        }
        predt = bt->data;
        b2 = JudgeBST(bt->rChild);
        return b2;
    }
}
