//
// Created by 张之豪 on 2021/11/30.
//
#include "../BiTNode.h"

#define MaxSize 50

int Btdepth(BiTree T) {
    if (!T) return 0;
    int front = -1, rear = -1;
    int last = 0, level = 0;
    BiTree Q[MaxSize];
    Q[++rear] = T;
    BiTree p;
    while (front < rear) {
        p = Q[++front];
        if (p->lChild) {
            Q[++rear] = p->lChild;
        }
        if (p->rChild) {
            Q[++rear] = p->rChild;
        }
        if (front == last) {
            level++;
            last = rear;
        }
    }
    return level;
}