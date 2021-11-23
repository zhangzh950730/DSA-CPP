//
// Created by zhang on 2020/12/20.
//

#include "ArrayList.h"

bool delMin(ArrayList &L, ElemType &value) {
    if (L.length == 0) return false;
    value = L.data[0];
    int pos = 0;
    for (int i = 1; i < L.length; ++i) {
        if (L.data[i] < value) {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}

int main() {
    int data[] = {5, 2, 1, 4, 3};
    struct ArrayList L = {data, 5, 5};
    ElemType elemType;
    delMin(L, elemType);

}