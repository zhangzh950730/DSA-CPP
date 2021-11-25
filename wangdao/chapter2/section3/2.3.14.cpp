//
// Created by 张之豪 on 2021/11/24.
//
#include "LinkedList.h"

LinkedList solution(LinkedList A, LinkedList B) {
    LNode *p = A->next, *q = B->next, *r, *s;
    LinkedList C = (LinkedList) malloc(sizeof(LNode));
    r = C;
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        } else {
            s = (LNode *) malloc(sizeof(LNode));
            s->data = p->data;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    r->next = NULL;
    return C;
}

int main() {
    LinkedList A = {};
    A = tailInsert(A);

    LinkedList B = {};
    B = tailInsert(B);
    LinkedList C = solution(A, B);

}