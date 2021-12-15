//
// Created by 张之豪 on 2021/12/9.
//
#include "../SSTable.h"

int SEqSrch(SSTable R, ElemType k) {
    int i = 0;
    int n = R.TableLen;
    while (R.elem[i] != k && i < n) {
        i++;
    }
    if (i < n && i > 0) {
        int temp = R.elem[i];
        R.elem[i] = R.elem[i - 1];
        R.elem[i - 1] = temp;
        return --i;
    } else return -1;
}