//
// Created by 张之豪 on 2021/11/25.
//
#include "../SqQueue.h"

int enQueue(SqQueue &Q, ElemType x) {
    if (Q.front == Q.rear && Q.tag == 1) return 0;

    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.tag = 1;
    return 1;
}

int deQueue(SqQueue &Q, ElemType &x) {
    if (Q.front == Q.rear && Q.tag == 0) return 0;

    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.tag = 0;
    return 1;
}