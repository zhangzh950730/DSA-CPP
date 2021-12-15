//
// Created by 张之豪 on 2021/12/14.
//
#include "../../Common.h"

bool isMinHeap(ElemType A[], int len) {
    if (len % 2 == 0) {
        if (A[len / 2] > A[len]) {
            return false;
        }
        for (int i = len / 2 - 1; i >= 1; --i) {
            if (A[i > A[i * 2] || A[i] > A[i * 2] + 1]) {
                return false;
            }
        }
    } else {
        for (int i = len / 2 - 1; i >= 1; --i) {
            if (A[i > A[i * 2] || A[i] > A[i * 2] + 1]) {
                return false;
            }
        }
    }
    return true;
}