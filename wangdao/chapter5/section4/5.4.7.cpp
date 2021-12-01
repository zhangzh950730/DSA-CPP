//
// Created by 张之豪 on 2021/12/1.
//

#include "CSNode.h"

void createCSTree_Degree(CSTree &T, ElemType e[], int degree[], int n) {
    CSNode *pointer = new CSNode[MaxSize];
    int i, j, d, k = 0;
    for (i = 0; i < n; ++i) {
        pointer[i].data = e[i];
        pointer[i].firstChild = pointer[i].nextSibling = nullptr;
    }
    for (i = 0; i < n; ++i) {
        d = degree[i];
        if (d) {
            k++;
            pointer[i].firstChild = &pointer[k];
            for (j = 2; j <= d; ++j) {
                k++;
                pointer[k - 1].nextSibling = &pointer[k];
            }
        }
    }
    T = &pointer[0];
    delete[] pointer;
}