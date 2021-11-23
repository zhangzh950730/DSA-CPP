//
// Created by zhang on 2021/7/17.
//

#include "../../chapter2/section2/ArrayList.h"
#include "8.3.h"

int partition(ElemType *A, int low, int high) {
    ElemType pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot) {
            high--;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot) {
            low++;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void quickSort(ElemType A[], int low, int high) {
    if (low < high) {
        int pivotPosition = partition(A, low, high);
        quickSort(A, low, pivotPosition - 1);
        quickSort(A, pivotPosition + 1, high);
    }
}

int main() {
    ElemType A[] = {49, 27, 13, 76, 97, 65, 38, 49};
    print(A, 8);
    quickSort(A, 0, 7);
    print(A, 8);
}
