//
// Created by zhang on 2020/12/25.
//
#include <iostream>

void print(const char *R);

using namespace std;

void reverse(char R[], int lo, int hi) {
    for (int i = 0; i < (hi - lo + 1) / 2; ++i) {
        char temp = R[i + lo];
        R[i + lo] = R[hi - i];
        R[hi - i] = temp;
    }
    print(R);
}

void solution(char R[], int n, int p) {
    reverse(R, 0, p - 1);
    reverse(R, p, n - 1);
    reverse(R, 0, n - 1);
}

int main() {
    char *R = new char[8]{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    solution(R, 8, 3);
    print(R);
    return 0;
}

void print(const char *R) {
    for (int i = 0; i < 8; ++i) {
        cout << R[i] << " ";
    }
    cout << endl;
}
