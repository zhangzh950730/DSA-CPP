//
// Created by zhang on 2021/7/17.
//

#include "../../chapter2/section2/SeqList.h"
#include "../section3/8.3.h"


void sink(ElemType a[], int k, int n) {
    while (2 * k <= n) {
        int j = 2 * k;
        if (j < n && a[j] < a[j + 1]) j++;
        if (a[k] >= a[j]) break;
        swap(a, k, j);
        k = j;
    }
}

void sort(ElemType a[], int len) {
    int N = len - 1;
    // 堆构造
    for (int k = N / 2; k >= 1; k--) {
        sink(a, k, N);
    }
    // 堆排序
    while (N > 1) {
        swap(a, 1, N--);
        sink(a, 1, N);
    }
}


int main() {
    ElemType A[] = {-1, 53, 17, 78, 9, 45, 65, 87, 32};
    print(A, 8);
    sort(A, 8);
    print(A, 8);

}