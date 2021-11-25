//
// Created by 张之豪 on 2021/11/25.
//
#include "../Common.h"

#define MaxSize 50

typedef struct {
    ElemType data[MaxSize];
    int front, rear;
    int tag;
} SqQueue;

void InitQueue(SqQueue &Q) {
    Q.rear = Q.front = 0;
}

bool IsEmpty(SqQueue Q) {
    return Q.rear == Q.front;
}

bool EnQueue(SqQueue &Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x) {
    if (IsEmpty(Q)) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}