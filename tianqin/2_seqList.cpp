//
// Created by zhang on 2020/8/2.
//
#include <cstdlib>
#include <iostream>

using namespace std;

#define maxSize 100

typedef struct {
    int data[maxSize];
    int length;
} SqList;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

typedef struct DLNode {
    int data;
    struct DLNode *prev;
    struct DLNode *succ;
} DLNode;

int findElem(SqList L, int x) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (x < L.data[i]) { break; }
    }
    return i;
}

void insertElem(SqList &L, int x) {
    int p, i;
    p = findElem(L, x);
    for (i = L.length - 1; i >= p; --i) {
        L.data[i + 1] = L.data[i];
    }
    L.data[p] = x;
    L.length++;
}

int deleteElem(SqList &L, int p, int &e) {
    if (p < 0 || p > L.length - 1) {
        return 0;
    }
    int i;
    e = L.data[p];
    for (i = p; i < L.length - 1; ++i) {
        L.data[i] = L.data[i + 1];
    }
    L.length--;
    return 1;
}

void initList(SqList &L) {
    L.length = 0;
}

int getElem(SqList &L, int p, int &e) {
    if (p < 0 || p > L.length - 1) {
        return 0;
    }
    e = L.data[p];
    return 1;
}

void merge(LNode *A, LNode *B, LNode *&C) {
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *r;
    C = A;
    C->next = nullptr;
    free(B);
    r = C;
    while (p != nullptr && q != nullptr) {
        if (p->data <= q->data) {
            r->next = p;
            p = p->next;
        } else {
            r->next = q;
            q = q->next;
        }
        r = r->next;
    }
    if (p != nullptr) {
        r->next = p;
    }
    if (q != nullptr) {
        r->next = q;
    }

}

int main() {
    cout << "hello,world c++" << endl;
    return 0;
}