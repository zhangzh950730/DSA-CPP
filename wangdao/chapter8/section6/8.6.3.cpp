//
// Created by 张之豪 on 2021/12/14.
//

void countSort(int A[], int B[], int n) {
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (A[j] < A[i]) {
                count++;
            }
        }
        B[count] = A[i];
    }
}
