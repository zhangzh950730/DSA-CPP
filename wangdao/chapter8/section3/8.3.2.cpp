//
// Created by 张之豪 on 2021/12/13.
//
#include "../../Common.h"
#include "8.3.h"


void bubbleSort(ElemType A[], int n) {
    int lo = 0, hi = n - 1;
    bool flag = true;
    while (lo < hi && flag) {
        flag = false;
        for (int i = lo; i < hi; ++i) {
            if (A[i] > A[i + 1]) {
                swap(A[i], A[i + 1]);
                flag = true;
            }
        }
        hi--;
        for (int i = hi; i > lo; --i) {
            if (A[i] < A[i - 1]) {
                swap(A[i], A[i - 1]);
                flag = true;
            }
        }
        lo++;
    }
}

int main() {
    ElemType A[] = {49, 27, 13, 76, 97, 65, 38, 49};
    print(A, 8);
    bubbleSort(A, 9);
    print(A, 8);
}