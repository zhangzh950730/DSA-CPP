//
// Created by 张之豪 on 2021/11/24.
//
#include "LinkedList.h"

void solution(LinkedList &L, ElemType min, ElemType max) {
    LNode *pre = L, *p = pre->next;
    while (p != NULL) {
        if (min < p->data && p->data < max) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = pre->next;
        }
    }
}
