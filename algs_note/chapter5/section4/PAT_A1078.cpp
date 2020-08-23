// Hashing
// Created by zhang on 2020/8/23.
//

#include <cstdio>
#include <cmath>

const int N = 10001;
bool hashTable[N] = {false};

bool isPrime(int n) {
    if (n < 2) return false;
    int sqr = (int) sqrt(n * 1.0);
    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, tSize, a;
    scanf("%d %d", &tSize, &n);
    while (!isPrime(tSize))tSize++;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        int m = a % tSize;
        if (!hashTable[m]) {
            hashTable[m] = true;
            if (i == 0) printf("%d", m);
            else printf(" %d", m);
        } else {
            int step;
            for (step = 1; step < tSize; ++step) {
                m = (a + step * step) % tSize;
                if (!hashTable[m]) {
                    hashTable[m] = true;
                    if (i == 0) printf("%d", m);
                    else printf(" %d", m);
                    break;
                }
            }
            if (step >= tSize) {
                if (i > 0) printf(" ");
                printf("-");
            }
        }
    }
    return 0;
}