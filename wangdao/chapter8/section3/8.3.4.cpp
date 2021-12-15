//
// Created by 张之豪 on 2021/12/14.
//
#include "../../Common.h"
#include "8.3.h"

int Partition2(ElemType A[], int lo, int hi) {
    int randIndex = lo + rand() % (hi - lo + 1);
    swap(A[randIndex], A[lo]);
    ElemType pivot = A[lo];
    int i = lo;
    for (int j = lo + 1; j <= hi; ++j) {
        if (A[j] < pivot) {
            swap(A[++i], A[j]);
        }
    }
    swap(A[i], A[lo]);
    return i;
}