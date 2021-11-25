//
// Created by 张之豪 on 2021/11/24.
//

#include "../../LinkedList.h"

void solution1(LinkedList L) {
    LNode *p, *r;
    p = L->next;
    L->next = NULL;
    while (p != NULL) {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
}

void solution2(LinkedList L) {
    LNode *pre, *p = L->next, *r = p->next;
    p->next = NULL;
    while (r != NULL) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
}

int main() {
    LinkedList L = {};
    L = tailInsert(L);
    solution1(L);
    solution2(L);

}