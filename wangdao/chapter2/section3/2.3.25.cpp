//
// Created by 张之豪 on 2021/11/25.
//
#include <cstdio>

typedef struct node {
    int data;
    struct node *next;
} NODE;

/**
 * 1.先找到中间节点,然后将后半段链表逆置
 * 2.从单链表前后两段依次各取一个节点,按要求重排
 *
 * 时间复杂度为O(n)
 */
void solution(NODE *h) {
    NODE *p = h, *q = h, *r, *s;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
        if (q->next != NULL) q = q->next;
    }
    q = p->next;
    p->next = NULL;
    while (q != NULL) {
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    s = h->next;
    q = p->next;
    p->next = NULL;
    while (q != NULL) {
        r = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q = r;
    }
}