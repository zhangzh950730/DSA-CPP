//
// Created by zhang on 2020/12/25.
//
#include "ArrayList.h"
#include <cstdlib>

bool merge(ArrayList &L1, ArrayList &L2, ArrayList &result) {
    if (L1.length + L2.length > result.length) return false;
    int i = 0, j = 0, k = 0;
    while (i < L1.length && j < L2.length) {
        if (L1.data[i] < L2.data[j]) {
            result.data[k++] = L1.data[i++];
        } else {
            result.data[k++] = L2.data[j++];
        }
    }
    while (i < L1.length) {
        result.data[k++] = L1.data[i++];
    }
    while (j < L2.length) {
        result.data[k++] = L2.data[j++];
    }
    result.length = k;
    return true;
}

int main() {
    int data1[] = {1, 3, 5, 8};
    struct ArrayList L1 = {data1, 4};
    int data2[] = {2, 4, 6, 7};
    struct ArrayList L2 = {data2, 4};

    int *dataResult = (ElemType *) malloc(sizeof(ElemType) * 8);
    struct ArrayList result = {dataResult, 8};
    merge(L1, L2, result);

}
