//
// Created by 张之豪 on 2021/11/25.
//
#include <cstdio>
#include <cstdlib>

#define maxSize 100

#define elemType int

typedef struct {
    elemType stack[maxSize];
    int top[2] = {-1, maxSize};
} stk;
stk s;

bool push(int i, elemType x) {
    if (i != 0 && i != 1) {
        printf("栈号输入不对\n");
        exit(0);
    }
    if (s.top[1] - s.top[0] == 1) {
        printf("栈已满\n");
        return false;
    }
    switch (i) {
        case 0:
            s.stack[++s.top[0]] = x;
            return true;
        case 1:
            s.stack[--s.top[1]] = x;
            return true;
    }
}

elemType pop(int i) {
    if (i != 0 && i != 1) {
        printf("栈号输入不对\n");
        exit(0);
    }
    switch (i) {
        case 0:
            if (s.top[0] == -1) {
                printf("栈已空\n");
                return NULL;
            }
            return s.stack[s.top[0]--];
        case 1:
            if (s.top[1] == maxSize) {
                printf("栈已空\n");
                return NULL;
            }
            return s.stack[s.top[1]++];
    }

}
