//
// Created by zhang on 2020/9/13.
//
#include <iostream>

using namespace std;

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt - 1; first < last; first++, last--) {
        inplace_swap(&a[first], &a[last]);
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    reverse_array(array, 5);
    for (int i : array) {
        printf("%d ", i);
    }
    printf("\n");

    int x = 0x87654321;
    int y = x & 0xff;
    int z = x ^~0xff;
    int h = x | 0xff;
    printf("%x\n", y);
    printf("%x\n", z);
    printf("%x\n", h);
    return 0;
}
