//
// Created by 张之豪 on 2021/12/14.
//
#include "../../Common.h"
#include "../section3/8.3.h"

void headAdjust(ElemType A[], int k, int len) {
    A[0] = A[k];
    for (int i = 2 * k; i <= len; i *= 2) {
        if (i < len && A[i] < A[i + 1]) {
            i++;
        }
        if (A[0] >= A[i]) break;
        else {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

void buildMaxHeap(ElemType A[], int len) {
    for (int i = len / 2; i > 0; i--) {
        headAdjust(A, i, len);
    }
}

void heapSort(ElemType A[], int len) {
    buildMaxHeap(A, len);
    for (int i = len; i > 1; --i) {
        swap(A[i], A[1]);
        headAdjust(A, 1, i - 1);
    }
}

