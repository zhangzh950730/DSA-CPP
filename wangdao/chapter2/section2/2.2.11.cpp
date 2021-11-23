//
// Created by 张之豪 on 2021/11/23.
//
#include <cstdio>
#include "ArrayList.h"

int solution1(int A[], int B[], int n) {
    int length = n * 2 - 1;
    length /= 2;
    int i = 0, j = 0;
    while (i + j < length) {
        if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }
    return A[i] < B[j] ? A[i] : B[j];
}

int solution2(int A[], int B[], int n) {
    int s1 = 0, d1 = n - 1, m1, s2 = 0, d2 = n - 1, m2;
    while (s1 != d1 || s2 != d2) {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (A[m1] == B[m2]) {
            return A[m1];
        } else if (A[m1] < B[m2]) {
            if ((s1 + d1) % 2 == 0) {
                s1 = m1;
                d2 = m2;
            } else {
                s1 = m1 + 1;
                d2 = m2;
            }
        } else {
            if ((s2 + d2) % 2 == 0) {
                s2 = m2;
                d1 = m1;
            } else {
                s2 = m2 + 1;
                d1 = m1;
            }
        }
    }
    return A[s1] < B[s2] ? A[s1] : B[s2];
}

int main() {
    int A1[] = {11, 13, 15, 17, 19};
    int B1[] = {2, 4, 6, 8, 20};
    int mid1 = solution1(A1, B1, 5);
    printf("mid1 = %d\n", mid1);

    int A2[] = {11, 13, 15, 17, 19};
    int B2[] = {2, 4, 6, 8, 20};
    int mid2 = solution1(A2, B2, 5);
    printf("mid2 = %d\n", mid2);
}
