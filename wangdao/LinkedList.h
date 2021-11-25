//
// Created by 张之豪 on 2021/11/23.
//

#include <cstdlib>
#include <cstdio>
#include "Common.h"

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkedList;

LinkedList headInsert(LinkedList &L) {
    LNode *s;
    int x;
    L = (LinkedList) malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

LinkedList tailInsert(LinkedList &L) {
    int x;
    L = (LinkedList) malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

LNode *getElem(LinkedList L, int i) {
    int j = 1;
    LNode *p = L->next;
    if (i == 0) return L;
    if (i < 1)return NULL;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

LNode *locateElem(LinkedList L, ElemType e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

void insert(LinkedList L, LNode *s, int i) {
    LNode *p = getElem(L, i - 1);
    s->next = p->next;
    p->next = s;
}

void del(LinkedList L, int i) {
    LNode *p = getElem(L, i - 1);
    LNode *q = p->next;
    p->next = q->next;
    free(q);
}

int length(LinkedList L) {
    LNode *p = L->next;
    int count = 0;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}

//int main() {
////    LinkedList L1 = {};
////    L1 = headInsert(L1);
//
//    LinkedList L2 = {};
//    L2 = tailInsert(L2);
//
//    LNode *elem = getElem(L2, 1);
//    elem = locateElem(L2, 7);
//
//    LNode s = {100};
//    insert(L2, &s, 2);
//
//    del(L2, 3);
//
//    int n = length(L2);
//    printf("n: %d\n", n);
//
//}