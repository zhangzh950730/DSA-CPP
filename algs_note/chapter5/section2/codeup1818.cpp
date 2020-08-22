// 最大公约数
// Created by zhang on 2020/8/22.
//
#include <cstdio>

int gcd(int a, int b) {
    if (b == 0)return a;
    else return gcd(b, a % b);
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF) {
        printf("%d\n", gcd(m, n));
    }
    return 0;
}

