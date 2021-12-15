//
// Created by 张之豪 on 2021/12/14.
//
#include "../../Common.h"

int partition(ElemType K[], int n) {
    int i = 1, j = n;
    ElemType pivot = K[j];
    while (i < j) {
        while (i < j && K[i++] <= pivot);
        if (i < j) K[j] = K[i];

        while (i < j && K[j--] >= pivot);
        if (i < j) K[i] = K[j];
    }
    K[i] = pivot;
    return i;
}