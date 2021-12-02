//
// Created by 张之豪 on 2021/12/2.
//
#include <cmath>
#include "BSTNode.h"

void Judge_AVL(BiTree bt, int &balance, int &h) {
    int bl = 0, br = 0, hl = 0, hr = 0;
    if (bt == nullptr) {
        h = 0;
        balance = 1;
    } else if (bt->lChild == nullptr && bt->rChild == nullptr) {
        h = 1;
        balance = 1;
    } else {
        Judge_AVL(bt->lChild, bl, hl);
        Judge_AVL(bt->rChild, br, hr);
        h = (hl > hr ? hl : hr) + 1;
        if (abs(hl - hr) < 2) {
            balance = bl && br;
        } else {
            balance = 0;
        }
    }
}