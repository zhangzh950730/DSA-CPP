//
// Created by 张之豪 on 2021/11/23.
//

#include "stdio.h"

#define INT_MAX 0x7fffffff

int abs(int a) {
    if (a < 0) return -a;
    else return a;
}

bool aIsMin(int a, int b, int c) {
    return a <= b && a <= c;
}

int solution(int A[], int n, int B[], int m, int C[], int p) {
    int i = 0, j = 0, k = 0, min = INT_MAX;
    while (i < n && j < m && k < p && min > 0) {
        int currentMin = abs(A[i] - B[j]) + abs(B[j] - C[k]) + abs(C[k] - A[i]);
        if (currentMin < min) {
            min = currentMin;
            if (aIsMin(A[i],B[j],C[k])) i++;
            else if (aIsMin(B[j],C[k],A[i])) j++;
            else k++;
        }
    }
    return min;
}

int main() {
    int A[] = {-1, 0, 9};
    int B[] = {-25, -10, 10, 11};
    int C[] = {2, 9, 17, 30, 41};
    int distance = solution(A, 3, B, 4, C, 5);
    printf("distance: %d\n", distance);
}