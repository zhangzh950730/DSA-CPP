// »®È­
// Created by zhang on 2020/8/13.
//

#include <cstdio>

int main() {
    int n, failA = 0, failB = 0;
    scanf("%d", &n);
    int a, ah, b, bh;
    while (n--) {
        scanf("%d %d %d %d", &a, &ah, &b, &bh);
        int result = a + b;
        if (result == ah && result != bh) {
            failB++;
        }
        if (result != ah && result == bh) {
            failA++;
        }
    }
    printf("%d %d\n", failA, failB);
    return 0;
}

