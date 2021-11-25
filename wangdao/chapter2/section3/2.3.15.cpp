//
// Created by 张之豪 on 2021/11/24.
//
#include "../../LinkedList.h"

LinkedList solution(LinkedList &la, LinkedList &lb) {
    LNode *pa = la->next, *pb = lb->next, *pc = la, *u;
    while (pa && pb) {
        if (pa->data == pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;

            u = pb;
            pb = pb->next;
            free(u);
        } else if (pa->data < pb->data) {
            u = pa;
            pa = pa->next;
            free(u);
        } else {
            u = pb;
            pb = pb->next;
            free(u);
        }
    }

    while (pa) {
        u = pa;
        pa = pa->next;
        free(u);
    }

    while (pb) {
        u = pb;
        pb = pb->next;
        free(u);
    }
    pc->next = NULL;
    free(lb);
    return la;
}

int main(){
    LinkedList A = {};
    A = tailInsert(A);

    LinkedList B = {};
    B = tailInsert(B);
    LinkedList C = solution(A, B);

}