//
// Created by zhang on 2020/12/21.
//
#include "ArrayList.h"

void reverse(ArrayList &L) {
    for (int i = 0; i < L.length / 2; ++i) {
        ElemType temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    struct ArrayList L = {data, 5};
    reverse(L);
}