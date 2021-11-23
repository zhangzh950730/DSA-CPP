//
// Created by zhang on 2021/7/17.
//

#include "../../chapter2/section2/ArrayList.h"
#include "8.3.h"

void bubbleSort(ElemType A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for (int j = n - 1; j > i; j--) {
            if (A[j - 1] > A[j]) {
                swap(A, j - 1, j);
                flag = true;
            }
        }
        if (!flag) {
            return;
        }
    }
}

int main() {
    ElemType A[] = {49, 27, 13, 76, 97, 65, 38, 49};
    print(A, 8);
    bubbleSort(A, 8);
    print(A, 8);
}




