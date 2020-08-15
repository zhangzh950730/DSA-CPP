// General Palindromic Number
// Created by zhang on 2020/8/15.
//

#include <cstdio>

bool judge(int A[40], int num) {
    for (int i = 0; i <= num / 2; ++i) {
        if (A[i] != A[num - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, b, z[40], num = 0;
    scanf("%d %d", &N, &b);
    do {
        z[num++] = N % b;
        N /= b;
    } while (N != 0);

    bool flag = judge(z, num);
    printf("%s\n", flag ? "Yes" : "No");
    for (int i = num - 1; i >= 0; --i) {
        printf("%d", z[i]);
        if (i != 0) printf(" ");
    }
    printf("\n");

    return 0;
}


