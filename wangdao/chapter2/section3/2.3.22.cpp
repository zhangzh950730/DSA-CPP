//
// Created by 张之豪 on 2021/11/24.
//

#include "../../LinkedList.h"

typedef struct Node {
    char data;
    struct Node *next;
} SNode;

int length(SNode *head) {
    int len = 0;
    while (head->next != NULL) {
        len++;
        head = head->next;
    }
    return len;
}
/**
 * 设计思想
 * 1.分别求出str1和str2的链表长度m,n
 * 2.将两个链表以表尾对齐,使指针p,q指向的节点到尾结点的距离相等
 * 3.p,q指针同步向后移动,当指向同一数据域时停止,即为共同后缀的起始位置
 *
 * 时间复杂度O(max(n,m))
 */
SNode *solution(SNode *str1, SNode *str2) {
    int m, n;
    SNode *p, *q;
    m = length(str1);
    n = length(str2);
    for (p = str1; m > n; m--) p = p->next;
    for (q = str2; n > m; n--) q = q->next;
    while (p->next != NULL && p->next != q->next) {
        p = p->next;
        q = q->next;
    }
    return p->next;
}