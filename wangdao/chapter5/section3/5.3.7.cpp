//
// Created by 张之豪 on 2021/11/30.
//
#include "queue"
#include "../BiTNode.h"

using namespace std;

bool IsComplete(BiTree T) {
    if (!T) return true;
    queue<BiTree> Q;
    Q.push(T);
    BiTree p;
    while (!Q.empty()) {
        p = Q.front(), Q.pop();
        if (p) {
            Q.push(p->lChild);
            Q.push(p->rChild);
        } else {
            while (!Q.empty()) {
                p = Q.front(), Q.pop();
                if (p) return false;
            }
        }
    }
    return true;
}
