// Reversible Primes
// Created by zhang on 2020/8/23.
//

#include <cstdio>
#include <cmath>

bool isPrime(int n) {
    if (n < 2) return false;
    int sqr = (int) sqrt(n * 1.0);
    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, radix, num[10000];
    while (scanf("%d", &n) != EOF) {
        scanf("%d", &radix);
        if (n < 0) break;
        if (!isPrime(n)) printf("No\n");
        else {
            int len = 0;
            do {
                num[len++] = n % radix;
                n /= radix;
            } while (n != 0);
            for (int i = 0; i < len; ++i) {
                n = n * radix + num[i];
            }
            if (isPrime(n)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}