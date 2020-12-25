//
// Created by zhang on 2020/12/21.
//
#include "SeqList.h"

void reverse(SeqList &L) {
    for (int i = 0; i < L.length / 2; ++i) {
        ElemType temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}