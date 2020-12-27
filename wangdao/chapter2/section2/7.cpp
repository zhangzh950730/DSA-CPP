//
// Created by zhang on 2020/12/25.
//
#include "SeqList.h"

bool merge(SeqList &L1, SeqList &L2, SeqList &result) {
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
