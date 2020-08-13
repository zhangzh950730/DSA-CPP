// 数组元素循环右移问题
// Created by zhang on 2020/8/13.
//

#include <cstdio>

int main() {
    int n, m, count = 0;
    scanf("%d %d", &n, &m);
    m = m % n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = n - m; i < n; ++i) {
        printf("%d", a[i]);
        if (++count < n) printf(" ");
    }
    for (int i = 0; i < n - m; ++i) {
        printf("%d", a[i]);
        if (++count < n) printf(" ");
    }
    return 0;
}