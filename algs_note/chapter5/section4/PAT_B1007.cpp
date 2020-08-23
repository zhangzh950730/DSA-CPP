// ËØÊı¶Ô²ÂÏë
// Created by zhang on 2020/8/23.
//

#include <cstdio>
#include <cmath>

bool isPrime(int n) {
    if (n < 2) return true;
    int sqr = (int) sqrt(n * 1.0);
    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 3; i + 2 <= n; i += 2) {
        if (isPrime(i) && isPrime(i + 2)) count++;
    }
    printf("%d", count);
    return 0;
}