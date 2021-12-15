//
// Created by 张之豪 on 2021/12/9.
//
#include "../SSTable.h"

int BinSearchRec(SSTable ST, ElemType key, int low, int high) {
    if (low > high) return 0;
    int mid = (low + high) / 2;
    if (key > ST.elem[mid]) {
        BinSearchRec(ST, key, mid + 1, high);
    } else if (key < ST.elem[mid]) {
        BinSearchRec(ST, key, low, mid - 1);
    }else {
        return mid;
    }
}