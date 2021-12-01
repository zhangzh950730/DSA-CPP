//
// Created by 张之豪 on 2021/11/30.
//
#include <cstdlib>
#include "../BiTNode.h"

typedef struct {
    BiTree t;
    int tag;
} stack;

stack s[50], s1[50];

BiTree Ancestor(BiTree ROOT, BiTNode *p, BiTNode *q) {
    int top = 0;
    BiTree bt = ROOT;
    while (bt != NULL || top > 0) {
        while (bt != NULL) {
            s[++top].t = bt;
            s[top].tag = 0;
            bt = bt->lChild;
        }
        while (top != 0 && s[top].tag == 1) {
            int top1;
            if (s[top].t == p) {
                for (int i = 0; i <= top; ++i) {
                    s1[i] = s[i];
                    top1 = top;
                }
            }
            if (s[top].t == q) {
                for (int i = top; i > 0; i--) {
                    for (int j = top1; j > 0; j--) {
                        if (s1[j].t == s[i].t)
                            return s[i].t;
                    }
                }
                top--;
            }
        }
        if (top != 0) {
            s[top].tag = 1;
            bt = s[top].t->rChild;
        }
    }
    return NULL;

}