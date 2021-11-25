//
// Created by 张之豪 on 2021/11/24.
//
#include "LinkedList.h"

void print(LinkedList L) {
    if (L == NULL) return;
    print(L->next);
    printf("data: %d\n", L->data);
}

void solution(LinkedList L) {
    if (L == NULL) return;
    print(L->next);
}

int main() {
    LinkedList L = {};
    L = tailInsert(L);
    solution(L);
}


