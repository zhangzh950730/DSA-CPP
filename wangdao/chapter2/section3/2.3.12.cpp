//
// Created by 张之豪 on 2021/11/24.
//
#include "../../LinkedList.h"

void solution(LinkedList &L) {
    LNode *p = L->next, *q;
    while (p != NULL){
        q = p->next;
        if (p->data == q->data) {
            p->next = q->next;
            free(q);
        }else {
            p = p->next;
        }
    }
}