//
// Created by 张之豪 on 2021/11/30.
//
#include "../BiTNode.h"
#include "queue"

using namespace std;

void DeleteXTree(BiTree &bt) {
    if (bt) {
        DeleteXTree(bt->lChild);
        DeleteXTree(bt->rChild);
        free(bt);
    }
}

void Search(BiTree bt, ElemType x) {
    queue<BiTree> Q;
    if (bt) {
        if (bt->data == x) {
            DeleteXTree(bt);
            exit(0);
        }
        Q.push(bt);
        BiTree p;
        while (!Q.empty()) {
            p = Q.front();
            Q.pop();
            if (p->lChild) {
                if (p->lChild->data == x) {
                    DeleteXTree(p->lChild);
                    p->lChild = NULL;
                } else Q.push(p->lChild);
            }
            if (p->rChild) {
                if (p->rChild->data == x) {
                    DeleteXTree(p->rChild);
                    p->rChild = NULL;
                } else Q.push(p->rChild);
            }
        }
    }
}