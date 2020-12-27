//
// Created by zhang on 2020/12/25.
//
#include "SeqList.h"

bool deleteST(SeqList *L, ElemType s, ElemType t) {
    if (L->length == 0 || s >= t) return false;
    int i, k = 0;
    for (i = 0; i < L->length; ++i) {
        if (L->data[i] >= s && L->data[i] <= t) {
            k++;
        } else {
            L->data[i - k] = L->data[i];
        }
    }
    return true;
}