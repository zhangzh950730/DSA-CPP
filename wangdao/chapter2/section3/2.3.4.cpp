//
// Created by 张之豪 on 2021/11/24.
//

#include "../../LinkedList.h"

void solution(LinkedList L) {
    LNode *pre = L, *p = pre->next;
    LNode *minPre = pre, *minP = p;
    while (p != NULL) {
        if (p->data < minP->data) {
            minP = p;
            minPre = pre;
        }
        pre = p;
        p = p->next;
    }
    minPre->next = minP->next;
    free(minP);
}

int main() {
    LinkedList L = {};
    L = tailInsert(L);
    solution(L);

}