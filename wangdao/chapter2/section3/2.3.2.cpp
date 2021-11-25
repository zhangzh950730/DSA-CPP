//
// Created by 张之豪 on 2021/11/24.
//

#include "LinkedList.h"

void delX(LinkedList &L, ElemType x) {
    if (L == NULL) return;
    LNode *p = L->next, *pre = L, *q;
    while (p != NULL) {
        if (p->data == x) {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        } else {
            pre = p;
            p = p->next;
        }
    }
}

int main() {
    LinkedList L = {};
    L = tailInsert(L);
    delX(L, 1);
}
