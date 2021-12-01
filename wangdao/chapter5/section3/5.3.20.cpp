#include <cstdio>

//
// Created by 张之豪 on 2021/12/1.
//
typedef struct node {
    char data[10];
    struct node *left, *right;
} BTree;

void BtreeToExp(BTree *root, int deep) {
    if (root == nullptr) return;
    else if (root->left == nullptr && root->right != nullptr) {
        printf("%s", root->data);
    } else {
        if (deep > 1) printf("(");
        BtreeToExp(root->left, deep + 1);
        printf("%s", root->data);
        BtreeToExp(root->right, deep + 1);
        if (deep > 1) printf(")");
    }
}

void BtreeToE(BTree *root) {
    BtreeToExp(root, 1);
}