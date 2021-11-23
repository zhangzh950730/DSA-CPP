//
// Created by 张之豪 on 2021/11/23.
//
#include "stdio.h"

int solution(int A[], int n) {
    int x = A[0], count = 1;
    for (int i = 1; i < n; ++i) {
        if (A[i] == x) {
            count++;
        } else {
            if (count > 0) {
                count--;
            } else {
                x = A[i];
            }
        }
    }
    if (count > 0) {
        for (int i = count = 0; i < n; ++i) {
            if (A[i] == x) count++;
        }
    }
    if (count > n / 2) return x;
    else return -1;
}

int main() {
    int A[] = {0, 5, 5, 3, 5, 7, 5, 5};
    int x = solution(A, 8);
    printf("x = %d\n", x);

    int B[] = {0, 3, 1, 7, 5, 5, 5, 5};
    x = solution(B, 8);
    printf("x = %d\n", x);

}