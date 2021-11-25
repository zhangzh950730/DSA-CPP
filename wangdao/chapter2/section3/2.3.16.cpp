//
// Created by 张之豪 on 2021/11/24.
//
#include "LinkedList.h"

bool solution(LinkedList A, LinkedList B) {
    LNode *p = A->next, *q = B->next, *pre = p;
    while (p && q) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        } else {
            pre = pre->next;
            p = pre;
            q = B;
        }
    }
    return q == NULL;
}


int main() {
    LinkedList A = {};
    A = tailInsert(A);

    LinkedList B = {};
    B = tailInsert(B);

    bool r = solution(A, B);

}