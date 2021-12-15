//
// Created by 张之豪 on 2021/12/14.
//

#include "../../Common.h"

void insertSort(ElemType A[], int m, int n) {
    for (int i = m + 1; i <= m + n; ++i) {
        A[0] = A[i];
        int j;
        for (j = i - 1; A[j] > A[0]; --j) {
            A[j + 1] = A[j];
        }
        A[j + 1] = A[0];
    }
}