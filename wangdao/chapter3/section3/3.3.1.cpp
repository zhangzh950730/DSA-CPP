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


bool solution(char *str) {
    SqStack S = *(SqStack *) malloc(sizeof(SqStack));
    initStack(S);
    int i = 0;
    char e;
    while (str[i] != '\0') {
        switch (str[i]) {
            case '(':
            case '[':
            case '{':
                push(S, str[i]);
                break;
            case ')':
                pop(S, e);
                if (e != '(') return false;
                break;

            case ']':
                pop(S, e);
                if (e != '[') return false;
                break;

            case '}':
                pop(S, e);
                if (e != '{') return false;
                break;
        }
    }
    if (!stackEmpty(S)) {
        printf("括号不匹配\n");
        return false;
    } else {
        printf("括号匹配\n");
        return true;
    }

}