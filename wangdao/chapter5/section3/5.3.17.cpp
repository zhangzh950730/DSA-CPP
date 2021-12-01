//
// Created by 张之豪 on 2021/12/1.
//

#include <cstdlib>
#include "../BiTNode.h"

int similar(BiTree T1, BiTree T2) {
    int leftS, rightS;
    if (T1 == NULL && T2 == NULL) {
        return 1;
    } else if (T1 == NULL || T2 == NULL) {
        return 0;
    } else {
        leftS = similar(T1->lChild, T2->lChild);
        rightS = similar(T1->rChild, T2->rChild);
        return leftS && rightS;
    }
}