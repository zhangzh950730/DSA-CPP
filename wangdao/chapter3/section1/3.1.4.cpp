//
// Created by 张之豪 on 2021/11/25.
//

#include "../../LinkedList.h"
#include "../../Stack.h"

bool solution(LinkedList L, int n) {
    int i;
    char s[n / 2];
    LNode *p = L->next;
    for (i = 0; i < n / 2; ++i) {
        s[i] = p->data;
        p = p->next;
    }
    i--;
    if (n % 2 == 1) p = p->next;
    while (p != NULL && s[i] == p->data) {
        i--;
        p = p->next;
    }
    return i == -1;
}