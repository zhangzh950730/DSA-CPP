//
// Created by 张之豪 on 2021/11/23.
//

#include <cstdlib>
#include "stdio.h"

int solution(int A[], int n) {
    int i, *B = (int *) malloc(sizeof(int) * n);
    for (i = 0; i < n; ++i) {
        B[A[i] - 1] = 1;
    }
    for (i = 0; i < n; ++i) {
        if (B[i] == 0) break;
    }
    return i + 1;
}

int main() {
    int A[] = {-5, 3, 2, 3};
    int x = solution(A, 4);
    printf("x = %d\n", x);

    int B[] = {1, 2, 3};
    x = solution(B, 3);
    printf("x = %d\n", x);
}