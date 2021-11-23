//
// Created by zhang on 2020/12/25.
//
#include "ArrayList.h"

bool deleteS2T(ArrayList &L, ElemType s, ElemType t) {
    if (L.length == 0 || s >= t) return false;
    int i, j = 0;
    for (i = 0; i < L.length; ++i) {
        if (s <= L.data[i] && L.data[i] <= t) {
            j++;
        } else {
            L.data[i - j] = L.data[i];
        }
    }
    L.length -= j;
    return true;
}

int main() {
    int data[] = {1, 1, 2, 3, 1, 2, 3, 1};
    struct ArrayList L = {data, 8};
    deleteS2T(L, 2, 3);

}