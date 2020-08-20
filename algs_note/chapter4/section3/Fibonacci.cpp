//
// Created by zhang on 2020/8/19.
//

#include <cstdio>

int fib(int n) {
    if (n <= 2) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", fib(n));
    return 0;
}