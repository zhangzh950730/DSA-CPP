//
// Created by 张之豪 on 2021/12/14.
//
#include "../../Common.h"
#include "8.3.h"

void solution(ElemType A[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        while (i < j && A[i++] % 2 != 0);
        while (j > i && A[j--] % 2 != 1);
        if (i < j) {
            swap(A[i], A[j]);
        }
        i++, j--;
    }
}