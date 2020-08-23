// ÊıËØÊı
// Created by zhang on 2020/8/23.
//

#include <cstdio>
#include <cmath>

const int maxn = 10000001;
int prime[maxn], num = 0;
bool isPrime[maxn] = {false};

void findPrime(int n) {
    for (int i = 2; i < maxn; ++i) {
        if (!isPrime[i]) {
            prime[num++] = i;
            if (num >= n) break;
            for (int j = i + i; j < maxn; j += i) {
                isPrime[j] = true;
            }
        }
    }
}

int main() {
    int m, n, count = 0;
    scanf("%d %d", &m, &n);
    findPrime(n);
    for (int i = m; i <= n; ++i) {
        printf("%d", prime[i - 1]);
        count++;
        if (count % 10 != 0 && i < n)printf(" ");
        else printf("\n");
    }
    return 0;
}