//
// Created by zhang on 2020/12/21.
//
#include "ArrayList.h"

bool deleteS2T(ArrayList &L, ElemType s, ElemType t) {
    if (L.length == 0 || s >= t) return false;
    int i, j;
    for (i = 0; i < L.length && L.data[i] < s; ++i);
    if (i == L.length) return false;
    for (j = i; j < L.length && L.data[j] <= t; ++j);
    while (j < L.length) {
        L.data[i++] = L.data[j++];
    }
    L.length = i;
    return true;
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    struct ArrayList L = {data, 5};
    deleteS2T(L, 2, 4);

}