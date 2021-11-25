//
// Created by 张之豪 on 2021/11/25.
//

#include <cstdlib>

typedef struct Node {
    int data;
    struct Node *link;
} NODE;

/**
 * 设计思想:
 * 使用n+1位辅助数组来存储每个data的绝对值是否出现过
 * 扫描链表,以当前节点的data的绝对值为索引,判断数组中对应索引是否为0
 * 如果0,则为出现过,数组对应索引的值置为0,链表节点指向下一个
 * 如果不为0,则表示出现过,删除当前节点,链表节点指向下一个
 *
 * 时间复杂度O(n),空间复杂度O(n+1)
 */
void solution(NODE *h, int n) {
    NODE *p = h, *r;
    int *q, m;
    q = (int *) malloc(sizeof(int) * (n + 1));
    while (p->link != NULL) {
        m = p->link->data > 0 ? p->link->data : -(p->link->data);
        if (*(q + m) == 0) {
            *(q + m) = 1;
            p = p->link;
        } else {
            r = p->link;
            p = r->link;
            free(r);
        }
    }
    free(q);
}
