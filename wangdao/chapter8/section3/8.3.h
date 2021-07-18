//
// Created by zhang on 2021/7/17.
//

#ifndef DSA_CPP_8_3_H
#define DSA_CPP_8_3_H

#endif //DSA_CPP_8_3_H

#include "iostream"

using namespace std;

void swap(ElemType *A, int i, int j) {
    ElemType temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void print(ElemType A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << " " << A[i];
    }
    cout << " " << endl;
}