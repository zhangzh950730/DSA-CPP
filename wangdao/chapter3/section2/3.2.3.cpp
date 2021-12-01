//
// Created by 张之豪 on 2021/11/25.
//

#include <cstdio>
#include "../../Stack.h"
#include "../SqQueue.h"

bool StackOverFlow(Stack S) {

}

int Enqueue(Stack &S1, Stack &S2, ElemType e) {
    ElemType x;
    if (!StackOverFlow(S1)) {
        push(S1, e);
        return 1;
    } else if (!stackEmpty(S2)) {
        printf("队列满\n");
        return 0;
    } else {
        while (!stackEmpty(S1)) {
            pop(S1, x);
            push(S2, x);
        }
        push(S1, e);
    }
    return 1;
}

int Dequeue(Stack &S1, Stack &S2, ElemType &x) {
    if (!stackEmpty(S2)) {
        pop(S2, x);
        return 1;
    } else if (stackEmpty(S1)) {
        printf("队列为空");
        return 0;
    } else {
        while (!stackEmpty(S1)) {
            pop(S1, x);
            push(S2, x);
        }
        pop(S2, x);
    }
    return 1;
}

int QueueEmpty(Stack &S1, Stack &S2) {
    return stackEmpty(S1) && stackEmpty(S2);
}
