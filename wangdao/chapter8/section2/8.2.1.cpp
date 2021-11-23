// 插入排序
// Created by zhang on 2021/7/14.
//

#include <iostream>
#include "../../chapter2/section2/ArrayList.h"

using namespace std;

void InsertSort(ElemType A[], int n) {
    int i, j;
    for (i = 2; i <= n; i++) {
        if (A[i] < A[i - 1]) {
            A[0] = A[i];
            for (j = i - 1; A[0] < A[j]; --j) {
                A[j + 1] = A[j];
            }
            A[j + 1] = A[0];
        }
    }
    A[0] = -1;
}

int main() {
    ElemType p[] = {-1, 49, 38, 65, 97, 76, 13, 27, 49};
    for (const auto &item : p) {
        cout << " " << item;
    }
    cout << " " << endl;
    InsertSort(p, 8);
    for (const auto &item : p) {
        cout << " " << item;
    }
    cout << " " << endl;
}