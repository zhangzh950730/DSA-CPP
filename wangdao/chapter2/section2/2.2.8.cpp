//
// Created by 张之豪 on 2021/11/23.
//
#include "ArrayList.h"

typedef int DataType;

bool exchange1(DataType A[], int length, int m, int n) {
    if (length == 0 || length != m + n) return false;
    int k = 0;
    DataType temp[m];
    for (int i = 0; i < m; ++i) {
        temp[k++] = A[i];
    }

    k = 0;
    for (int i = n - 1; i < length; ++i) {
        A[k++] = A[i];
    }
    for (int i = 0; i < m; ++i) {
        A[k++] = temp[i];
    }
    return true;
}


void reverse(DataType A[], int length, int left, int right) {
    if (left >= right || right >= length) return;
    int mid = (left + right) / 2;
    for (int i = 0; i <= mid - left; ++i) {
        DataType temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
}

void exchange2(DataType A[], int length, int m, int n) {
    reverse(A, length, 0, m + n - 1);
    reverse(A, length, 0, n - 1);
    reverse(A, length, n, m + n - 1);
}

int main() {
    int A1[] = {1, 2, 3, 4, 5};
    exchange1(A1, 5, 2, 3);

    int A2[] = {1, 2, 3, 4, 5};
    exchange2(A2, 5, 2, 3);
}