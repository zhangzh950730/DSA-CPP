//
// Created by zhang on 2021/7/17.
//

#include "../../chapter2/section2/SeqList.h"
#include "../section3/8.3.h"

void selectSort(ElemType A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(A, min, i);
        }
    }
}

int main() {
    ElemType A[] = {49, 27, 13, 76, 97, 65, 38, 49};
    print(A, 8);
    selectSort(A, 8);
    print(A, 8);
}
