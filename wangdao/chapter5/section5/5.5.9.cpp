//
// Created by 张之豪 on 2021/12/2.
//

#include "BSTNode.h"

ElemType MaxKey(BiTree bt){
    while (bt->rChild != nullptr) {
        bt = bt->rChild;
    }
    return bt->data;
}


ElemType MinKey(BiTree bt){
    while (bt->lChild != nullptr) {
        bt = bt->lChild;
    }
    return bt->data;
}