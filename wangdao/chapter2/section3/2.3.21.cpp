//
// Created by 张之豪 on 2021/11/24.
//
#include "../../LinkedList.h"

/**
 * 设计思想
 * 定义双指针p和q,初始都指向链表的第一个节点
 * p指针沿链表移动,当p移动了k步以后,q开始与p同步移动
 * 当p到达链表最后一个节点时,q指向的就是倒数第k个节点
 *
 * 实现步骤
 * 1.count = 0,p,q 指向链表的第一个节点
 * 2.循环p不为空
 *  2.1 if count<k count++ else q指向下一个节点
 *  2.2 p指向下一个节点
 * 3.如果count值等于k值,则查找成功,打印q的数据域,返回1; 否则就是查找失败,返回0
 */
int solution(LinkedList &list, int k) {
    LNode *p = list->next, *q = p;
    int count = 0;
    while (p != NULL) {
        if (count < k) count++;
        else q = q->next;
        p = p->next;
    }
    if (count < k) return 0;
    printf("%d", q->data);
    return 1;
}

int main() {
    LinkedList L = {};
    L = tailInsert(L);
    solution(L, 3);

}