//
// Created by 张之豪 on 2021/11/23.
//

#include "ArrayList.h"

void searchExchangeInsert(ArrayList &L, ElemType x) {
    int lo = 0, hi = L.length - 1, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (L.data[mid] == x) { break; }
        else if (L.data[mid] < x) lo = mid + 1;
        else hi = mid - 1;
    }

    if (L.data[mid] == x && mid != L.length - 1) {
        ElemType t = L.data[mid];
        L.data[mid] = L.data[mid + 1];
        L.data[mid + 1] = t;
    }

    if (lo > hi) {
        int i;
        for (i = L.length - 1; i > hi; --i) {
            L.data[i + 1] = L.data[i];
        }
        L.data[i + 1] = x;
    }

}

int main() {
    int data1[] = {1, 3, 5, 8};
    struct ArrayList L1 = {data1, 4};
    searchExchangeInsert(L1, 5);

    int data2[] = {1, 3, 5, 8};
    struct ArrayList L2 = {data2, 4};
    searchExchangeInsert(L2, 8);

    int data3[] = {1, 3, 5, 8};
    struct ArrayList L3 = {data3, 4};
    searchExchangeInsert(L3, 0);

}