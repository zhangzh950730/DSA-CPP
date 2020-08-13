// 害死人不偿命的(3n+1)猜想
// Created by zhang on 2020/8/13.
//
#include <cstdio>

int main() {
    int n, step = 0;
    scanf("%d", &n);
    while (n != 1) {
        if (n % 2) {
            n = (3 * n + 1) / 2;
        } else {
            n /= 2;
        }
        step++;
    }
    printf("%d\n", step);
    return 0;
}