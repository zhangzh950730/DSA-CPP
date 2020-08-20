//
// Created by zhang on 2020/8/19.
//

#include <cstdio>

const int MAX_N = 11;
int n, P[MAX_N], hashTable[MAX_N] = {false};

void generateP(int index) {
    if (index == n + 1) {
        for (int i = 1; i <= n; ++i) {
            printf("%d", P[i]);
        }
        printf("\n");
        return;
    }
    for (int x = 1; x <= n; ++x) {
        if (!hashTable[x]) {
            P[index] = x;
            hashTable[x] = true;
            generateP(index + 1);
            hashTable[x] = false;
        }
    }
}

int main() {
    n = 3;
    generateP(1);
    return 0;
}
