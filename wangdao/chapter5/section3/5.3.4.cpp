//
// Created by 张之豪 on 2021/11/29.
//
#include "stack"
#include "queue"
#include "iostream"
#include "../BiTNode.h"

using namespace std;

void visit(ElemType data) {
    cout << data << endl;
}

void solution(BiTree T) {
    stack<BiTree> S;
    queue<BiTree> Q;
    BiTree p;
    if (T != NULL) {
        Q.push(T);
        while (!Q.empty()) {
            p = Q.front(), Q.pop();
            S.push(p);
            if (p->lChild) Q.push(p->lChild);
            if (p->rChild)Q.push(p->rChild);
        }
        while (!Q.empty()) {
            p = S.top(), S.pop();
            visit(p->data);
        }
    }

}