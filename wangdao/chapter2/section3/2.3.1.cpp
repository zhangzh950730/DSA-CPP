//
// Created by 张之豪 on 2021/11/24.
//

#include "../../LinkedList.h"

void delX(LinkedList L, ElemType x) {
    if (L == nullptr) return;
    if (L->data == x) {
        LNode *p = L;
        L = L->next;
        free(p);
        delX(L, x);
    } else delX(L->next, x);
}

int main() {
    LinkedList L = {};
    L = tailInsert(L);
    delX(L, 1);

}