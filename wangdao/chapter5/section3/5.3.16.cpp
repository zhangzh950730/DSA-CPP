//
// Created by 张之豪 on 2021/12/1.
//

#include "../../LinkedList.h"
#include "../BiTNode.h"

BiTree head, pre = NULL;

BiTree InOrder(BiTree bt) {
    if (bt) {
        InOrder(bt->lChild);
        if (bt->lChild == NULL && bt->rChild == NULL) {
            if (pre == NULL) {
                head = bt;
                pre = bt;
            } else {
                pre->rChild = bt;
                pre = bt;
            }
        }
        InOrder(bt->rChild);
        pre->rChild = NULL;
    }
    return head;
}