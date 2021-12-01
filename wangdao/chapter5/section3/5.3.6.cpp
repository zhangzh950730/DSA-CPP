//
// Created by 张之豪 on 2021/11/30.
//

#include <cstdlib>
#include "../BiTNode.h"

/**
 *
 * @param A 先序序列
 * @param B 中序序列
 * @param l1 先序序列第一个节点下标
 * @param h1 先序序列最后一个节点下标
 * @param l2 中序序列第一个节点下标
 * @param h2 中序序列最后一个节点下标
 * @return 生成树的根节点
 */
BiTree PreInCreat(ElemType A[], ElemType B[], int l1, int h1, int l2, int h2) {
    BiTNode *root = (BiTNode *) malloc(sizeof(BiTNode));
    root->data = A[l1]; //根节点
    int i;
    for (i = l2; B[i] != root->data; ++i); // 根节点在中序序列中的划分
    int llen = i - l2, rlen = h2 - i; //左右子树长度
    if (llen) { //递归建立左子树
        root->lChild = PreInCreat(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
    } else root->lChild = NULL;

    if (rlen) { //递归建立右子树
        root->rChild = PreInCreat(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
    } else root->rChild = NULL;
    return root;
}