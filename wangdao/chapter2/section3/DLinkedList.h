//
// Created by 张之豪 on 2021/11/24.
//
#include <cstdlib>
#include <cstdio>
#include "../../Common.h"

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
    int freq;
} DNode, *DLinkedList;

void insert(DNode *p, DNode *s) {
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}

void del(DNode *q) {
    q->prior->next = q->next;
    q->next->prior = q->prior;
    free(q);
}