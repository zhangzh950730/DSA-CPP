//
// Created by 张之豪 on 2021/11/24.
//

#include "DLinkedList.h"

DLinkedList locate(DLinkedList &L, ElemType x) {
    DNode *p = L->next, *q;
    while (p && p->data != x) p = p->next;
    if (!p) printf("不存在值为%d的节点\n", x);
    else {
        p->freq++;
        if (p->next != NULL) {
            p->next->prior = p->prior;
        }
        p->prior->next = p->next;
        q = p->prior;
        while (q != L && q->freq <= p->freq) {
            q = q->prior;
        }
        p->next = q->next;
        q->next->prior = p;
        p->prior = q;
        q->next = p;
    }
    return p;
}