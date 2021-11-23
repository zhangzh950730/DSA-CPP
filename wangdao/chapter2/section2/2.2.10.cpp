//
// Created by zhang on 2020/12/25.
//
#include <iostream>

using namespace std;

void print(const int R[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << R[i] << " ";
    }
    cout << endl;
}

void reverse(int R[], int left, int right) {
    for (int i = 0; i < (right - left + 1) / 2; ++i) {
        int temp = R[left + i];
        R[left + i] = R[right - i];
        R[right - i] = temp;
    }
}

/**
 * 例如数组为 1, 2, 3, 4, 5, n为5, p为2
 * 1. 先逆转整个数组, 变为 5, 4, 3, 2, 1
 * 2. 再逆转0到p-1, 变为 3, 4, 5, 2, 1
 * 3. 再逆转p到n-1, 变为 3, 4, 5, 1, 2
 * 算法的时间复杂度为 O(n/2) + O(p/2) + O((n - p)/2) ~= O(n)
 * 算法的空间复杂度为 O(1)
 */
void solution(int R[], int n, int p) {
    reverse(R, 0, n - 1);
    reverse(R, 0, p - 1);
    reverse(R, p, n - 1);
}

int main() {
    int R[] = {1, 2, 3, 4, 5};
    solution(R, 5, 2);

}


