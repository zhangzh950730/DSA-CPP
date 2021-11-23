//
// Created by zhang on 2020/12/21.
//
#include "ArrayList.h"

void deleteX(ArrayList &L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

int main() {
    int data[] = {1, 1, 2, 3, 1, 2, 3, 1};
    struct ArrayList L = {data, 8};
    deleteX(L, 1);

}