//
// Created by zhang on 2020/12/21.
//
#include "SeqList.h"

void deleteX(SeqList &L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}