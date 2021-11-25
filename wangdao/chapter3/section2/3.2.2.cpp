//
// Created by 张之豪 on 2021/11/25.
//

#include "../Stack.h"
#include "../SqQueue.h"

void inverser(SqStack &S, SqQueue &Q) {
    ElemType x;
    while (!IsEmpty(Q)) {
        DeQueue(Q, x);
        push(S, x);
    }
    while (!stackEmpty(S)) {
        pop(S, x);
        EnQueue(Q, x);
    }
}