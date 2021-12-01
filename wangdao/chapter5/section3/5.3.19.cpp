//
// Created by 张之豪 on 2021/12/1.
//
#include "../../Common.h"

typedef struct BiTNode {
    int weight;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int preOrderWPL(BiTree root, int deep) {
    static int wpl = 0;
    if (root->lchild == nullptr && root->rchild == nullptr) {
        wpl += deep * root->weight;
    }
    if (root->lchild != nullptr) {
        preOrderWPL(root->lchild, deep + 1);
    }
    if (root->rchild != nullptr) {
        preOrderWPL(root->rchild, deep + 1);
    }
    return wpl;
}

int preOrderWPL(BiTree T) {
    return preOrderWPL(T, 0);
}

int levelOrderWPL(BiTree T) {
    BiTree q[MaxSize];
    int front = 0, rear = 0;
    int wpl = 0, deep = 0;
    BiTree lastNode = T;
    BiTree newLastNode = nullptr;
    q[rear++] = T;
    while (front != rear) {
        BiTree t = q[front++];
        if (t->lchild == nullptr && t->rchild == nullptr) {
            wpl += deep * t->weight;
        }
        if (t->lchild != nullptr) {
            q[rear++] = t->lchild;
            newLastNode = t->lchild;
        }
        if (t->rchild != nullptr) {
            q[rear++] = t->rchild;
            newLastNode = t->rchild;
        }
        if (t == lastNode) {
            lastNode = newLastNode;
            deep++;
        }
    }
    return wpl;
}


