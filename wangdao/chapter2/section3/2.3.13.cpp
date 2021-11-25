//
// Created by 张之豪 on 2021/11/24.
//
#include "../../LinkedList.h"

void solution(LinkedList &La, LinkedList &Lb) {
    LNode *pa = La->next, *pb = Lb->next, *r;
    La->next = NULL;
    while (pa && pb) {
        if (pa->data < pb->data) {
            r = pa->next;
            pa->next = La->next;
            La->next = pa;
            pa = r;
        } else {
            r = pb->next;
            pb->next = La->next;
            La->next = pb;
            pb = r;
        }
    }
    if (pa) {
        pb = pa;
    }
    while (pb) {
        r = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = r;
    }
    free(Lb);
}

int main() {
    LinkedList L1 = {};
    L1 = tailInsert(L1);

    LinkedList L2 = {};
    L2 = tailInsert(L2);
    solution(L1, L2);

}