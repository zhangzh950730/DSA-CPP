//
// Created by Administrator on 2021/7/20.
//

#include <stdio.h>

//
// Created by Administrator on 2021/7/20.
//
typedef int ElemType;

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lChild, *rChild;
} BiTNode, *BiTree;

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

void inOrder(BiTree T) {
    if (T != NULL) {
        inOrder(T->lChild);
        visit(T);
        inOrder(T->rChild);
    }
}

void postOrder(BiTree T) {
    if (T != NULL) {
        postOrder(T->lChild);
        postOrder(T->rChild);
        visit(T);
    }
}

void inOrder2(BiTree T) {

}

int main() {
    BiTNode one = {1};
    BiTNode two = {2};
    BiTNode three = {3};
    BiTNode four = {4};
    BiTNode five = {5};
    BiTNode six = {6};

    one.lChild = &two;
    one.rChild = &three;
    two.rChild = &four;
    three.rChild = &five;
    four.lChild = &six;
    preOrder(&one);
    printf("\n");
    inOrder(&one);
    printf("\n");
    postOrder(&one);
    printf("\n");
}