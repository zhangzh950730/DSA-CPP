//
// Created by 张之豪 on 2021/11/24.
//
#include "LinkedList.h"

LinkedList solution(LinkedList &A) {
    int i = 0;
    LinkedList B = (LinkedList) malloc(sizeof(LNode));
    B->next = NULL;
    LNode *ra = A, *rb = B;
    LNode *p = A->next;
    A->next = NULL;
    while (p != NULL) {
        i++;
        if (i % 2 == 0) {
            rb->next = p;
            rb = p;
        } else {
            ra->next = p;
            ra = p;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
    return B;
}

int main() {

    LinkedList A = {};
    A = tailInsert(A);
    LinkedList B = solution(A);

}