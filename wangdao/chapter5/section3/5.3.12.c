//
// Created by 张之豪 on 2021/11/30.
//

#include <printf.h>
#include <stdlib.h>
#include "../BiTNode.h"

typedef struct {
    BiTree t;
    int tag;
} stack;

void Search(BiTree bt, ElemType x) {
    stack s[50];
    int top = 0;
    while (bt || top > 0) {
        while (bt && bt->data != x) {
            s[++top].t = bt;
            s[top].tag = 0;
            bt = bt->lChild;
        }
        if (bt->data == x) {
            printf("所查找节点的所有祖先节点的值为:\n");
            for (int i = 1; i <= top; ++i) {
                printf("%d", s[i].t->data);
            }
            exit(1);
        }
        while (top != 0 && s[top].tag == 1) top--;

        if (top != 0) {
            s[top].tag = 1;
            bt = s[top].t->rChild;
        }
    }
}