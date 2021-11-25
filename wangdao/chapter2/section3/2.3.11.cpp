//
// Created by 张之豪 on 2021/11/24.
//
#include "../../LinkedList.h"

LinkedList solution(LinkedList &A) {
    LinkedList B = (LinkedList) malloc(sizeof(LNode));
    B->next = NULL;
    LNode *p = A->next, *q;
    LNode *ra = A;
    while (p != NULL) {
        ra->next = p;
        ra = p;

        if (p != NULL) q = p->next;

        p->next = B->next;
        B->next = p;
        p = q;
    }
    ra->next = NULL;
    return B;
}