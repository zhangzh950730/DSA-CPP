//
// Created by 张之豪 on 2021/11/24.
//
#include "LinkedList.h"

void solution(LinkedList L) {
    LNode *p = L->next, *pre;
    LNode *r = p->next;
    p->next = NULL;
    p = r;
    while (p != NULL) {
        r = p->next;
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data) {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}

int main() {
    LinkedList L = {};
    L = tailInsert(L);
    solution(L);

}
