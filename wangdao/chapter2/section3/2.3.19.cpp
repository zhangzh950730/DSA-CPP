//
// Created by 张之豪 on 2021/11/24.
//
#include "LinkedList.h"

void solution(LinkedList &L) {
    LNode *p, *pre, *minP, *minPre;
    while (L->next != L) {
        p = L->next;
        pre = L;
        minP = p;
        minPre = pre;
        while (p != L) {
            if (p->data < minP->data) {
                minP = p;
                minPre = pre;
            }
            pre = p;
            p = p->next;
        }
        printf("%d ", minP->data);
        minPre->next = minP->next;
        free(minP);
    }
    free(L);
}

int main() {
    LinkedList L = {};
    L = tailInsert(L);
    int n = length(L);
    LNode *tail = getElem(L, n);
    tail->next = L;
    solution(L);
}