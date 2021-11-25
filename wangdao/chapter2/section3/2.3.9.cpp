//
// Created by 张之豪 on 2021/11/24.
//
#include "LinkedList.h"

void solution(LinkedList head) {
    while (head->next != NULL) {
        LNode *pre = head;
        LNode *p = pre->next;
        while (p->next != NULL) {
            if (p->next->data < pre->next->data) {
                pre = p;
            }
            p = p->next;
        }
        printf("d: %d\n", pre->next->data);
        LNode *r = pre->next;
        pre->next = r->next;
        free(r);
    }
    free(head);
}

int main() {
    LinkedList L = {};
    L = tailInsert(L);
    solution(L);
}
