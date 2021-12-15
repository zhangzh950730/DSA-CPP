//
// Created by 张之豪 on 2021/12/14.
//

#include "../../LinkedList.h"

void selectSort(LinkedList &L) {
    LNode *h = L, *p, *q, *r, *s;
    L = NULL;
    while (h != NULL) {
        p = s = h;
        q = r = NULL;
        while (p != NULL) {
            if (p->data > s->data) {
                s = p;
                r = q;
            }
            q = p;
            p = p->next;
        }
        if (s == h) {
            h = h->next;
        } else {
            r->next = s->next;
        }
        s->next = L, L = s;
    }
}