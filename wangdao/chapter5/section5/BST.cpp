//
// Created by 张之豪 on 2021/12/1.
//

#include <cstdlib>
#include "BSTNode.h"

BSTNode *BST_Search(BiTree T, ElemType key) {
    while (T != nullptr && key != T->data) {
        if (key < T->data) T = T->lChild;
        else T = T->rChild;
    }
    return T;
}

int BST_Insert(BiTree &T, ElemType key) {
    if (T == nullptr) {
        T = (BiTree) malloc(sizeof(BSTNode));
        T->data = key;
        T->lChild = T->rChild = nullptr;
        return 1;

    } else if (key == T->data) {
        return 0;
    } else if (key < T->data) {
        return BST_Insert(T->lChild, key);
    } else {
        return BST_Insert(T->rChild, key);
    }
}

void Creat_BST(BiTree &T, ElemType str[], int n) {
    T = NULL;
    int i = 0;
    while (i < n) {
        BST_Insert(T, str[i++]);
    }
}