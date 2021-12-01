#include <stdio.h>
#include <stdlib.h>
#include "../BiTNode.h"
#include "stack"

using namespace std;

void visit(BiTree x) {
    printf(" %d", x->data);
}

void preOrder(BiTree T) {
    if (T != NULL) {
        visit(T);
        preOrder(T->lChild);
        preOrder(T->rChild);
    }
}

void preOrder2(BiTree T) {
    stack<BiTree> S;
    BiTree p = T;
    while (p || !S.empty()) {
        if (p) {
            visit(p);
            S.push(p);
            p = p->lChild;
        } else {
            p = S.top();
            S.pop();
            p = p->rChild;
        }
    }
}

void inOrder(BiTree T) {
    if (T != NULL) {
        inOrder(T->lChild);
        visit(T);
        inOrder(T->rChild);
    }
}

void inOrder2(BiTree T) {
    stack<BiTree> S;
    BiTree p = T;
    while (p || !S.empty()) {
        if (p) {
            S.push(p);
            p = p->lChild;
        } else {
            p = S.top();
            S.pop();
            visit(p);
            p = p->rChild;
        }
    }
}

void postOrder(BiTree T) {
    if (T != NULL) {
        postOrder(T->lChild);
        postOrder(T->rChild);
        visit(T);
    }
}

void postOrder2(BiTree T) {
    stack<BiTree> S;
    BiTree p = T, r = NULL;
    while (p || !S.empty()) {
        if (p) {
            S.push(p);
            p = p->lChild;
        } else {
            p = S.top();
            if (p->rChild && p->rChild != r) {
                p = p->rChild;
            } else {
                S.pop();
                visit(p);
                r = p;
                p = NULL;
            }

        }
    }
}

int main() {
    BiTree root = (BiTree) malloc(sizeof(BiTree));
    root->data = 1;
    BiTNode two = {2};
    BiTNode three = {3};
    BiTNode four = {4};
    BiTNode five = {5};
    BiTNode six = {6};

    root->lChild = &two;
    root->rChild = &three;
    two.rChild = &four;
    three.rChild = &five;
    four.lChild = &six;

//    preOrder(root);
//    printf("\n");

    inOrder(root);
    printf("\n");
    inOrder2(root);
    printf("\n");

//    postOrder(root);
//    printf("\n");

}