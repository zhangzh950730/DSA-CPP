//
// Created by 张之豪 on 2021/11/25.
//

#include <cstdlib>
#include <cstdio>

#define ElemType char
#define MaxSize 50

typedef struct Stack {
    ElemType data[50];
    int top;
} SqStack;

void initStack(SqStack &stack) {
    stack.top = -1;
}

bool push(SqStack &stack, ElemType x) {
    if (stack.top == MaxSize - 1) return false;
    stack.data[++stack.top] = x;
    return true;
}

bool pop(SqStack &stack, ElemType &x) {
    if (stack.top == -1)return false;
    x = stack.data[stack.top--];
    return true;
}

bool stackEmpty(SqStack stack) {
    return stack.top == -1;
}

void solution(char *train) {
    char *p = train, *q = train, c;
    SqStack s;
    initStack(s);
    while (*p) {
        if (*p == 'H') push(s, *p);
        else *(q++) = *p;
        p++;
    }
    while (!stackEmpty(s)) {
        pop(s, c);
        *(q++) = c;
    }
}
