// 折半插入排序
// Created by zhang on 2021/7/15.
//

#include <iostream>
#include "../../chapter2/section2/SeqList.h"

using namespace std;

void InsertSort(ElemType A[], int n) {
    int i, j, low, high, mid;
    for (i = 2; i <= n; i++) {
        A[0] = A[i];
        low = 1;
        high = i - 1;

        while (low <= high) {
            mid = (low + high) / 2;
            if (A[mid] > A[0]) {
                high = mid - 1;
            } else low = mid + 1;
        }
        for (j = i - 1; j >= high; --j) {
            A[j + 1] = A[j];
        }
        A[high + 1] = A[0];
    }
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
