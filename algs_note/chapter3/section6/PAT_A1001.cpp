#include <cstdio>

// A+B Format
// Created by zhang on 2020/8/16.
//
int main() {
    int a, b, sum, num[10], i = 0;
    scanf("%d%d", &a, &b);
    sum = a + b;
    if (sum < 0) {
        printf("-");
        sum = -sum;
    }
    do {
        num[i++] = sum % 10;
        sum /= 10;
    } while (sum);

    for (i--; i >= 0; --i) {
        printf("%d", num[i]);
        if (i > 0 && i % 3 == 0) printf(",");
    }
    return 0;
}