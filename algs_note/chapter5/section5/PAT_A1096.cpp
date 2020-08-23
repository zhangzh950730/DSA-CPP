// Consecutive Factors
// Created by zhang on 2020/8/23.
//
#include <cstdio>
#include <cmath>

typedef long long LL;

int main() {
    LL n;
    scanf("%lld", &n);
    LL sqr = (LL) sqrt(n), ansI = 0, ansLen = 0;
    for (LL i = 2; i <= sqr; i++) {
        LL temp = 1, j = i;
        while (true) {
            temp *= j;
            if (n % temp != 0) break;
            if (j - i + 1 > ansLen) {
                ansI = i;
                ansLen = j - i + 1;
            }
            j++;
        }
    }
    if (ansLen == 0) {
        printf("1\n%lld", n);
    } else {
        printf("%lld\n", ansLen);
        for (LL i = 0; i < ansLen; ++i) {
            printf("%lld", ansI + i);
            if (i < ansLen - 1) printf("*");
        }
    }
    return 0;
}