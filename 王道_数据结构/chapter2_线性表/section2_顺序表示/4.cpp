//
// Created by zhang on 2020/12/21.
//
#include "SeqList.h"

bool deleteStoT(SeqList &L, ElemType s, ElemType t) {
    if (s >= t || L.length == 0) return false;
    int i, j;
    for (i = 0; i < L.length && L.data[i] < s; ++i) {}
    if (i > L.length) return false;
    for (j = i; j < L.length && L.data[j] <= t; ++j) {}
    for (; j < L.length; i++, j++) {
        L.data[i] = L.data[j];
    }
    L.length = i;
    return true;
}