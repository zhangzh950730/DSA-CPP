//
// Created by 张之豪 on 2021/11/24.
//

#include "DLinkedList.h"

bool solution(DLinkedList L) {
    DNode *p = L->next, *q = L->prior;
    while (p != q && q->next != p) {
        if (p->data == q->data) {
            p = p->next;
            q = q->prior;
        } else return false;
    }
    return true;
}