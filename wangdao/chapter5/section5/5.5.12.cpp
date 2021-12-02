//
// Created by 张之豪 on 2021/12/2.
//

#include "BSTNode.h"

BSTNode *Search_Small(BiTree t, int k) {
    if (k < 1 || k > t->count)return nullptr;
    if (t->lChild == nullptr) {
        if (k == 1) return t;
        else return Search_Small(t->rChild, k - 1);
    } else {
        if (t->lChild->count == k - 1)return t;
        if (t->lChild->count > k - 1) {
            return Search_Small(t->lChild, k);
        }
        if (t->lChild->count < k - 1) {
            return Search_Small(t->rChild, k - t->lChild->count - 1);
        }
    }
}