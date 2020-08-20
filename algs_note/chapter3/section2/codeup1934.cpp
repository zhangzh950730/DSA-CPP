// ’“x
// Created by zhang on 2020/8/14.
//

#include <cstdio>

const int MAX_N = 200;
int a[MAX_N];

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);

    int k;
    for (k = 0; k < n; ++k) {
        if (a[k] == x) {
            break;
        }
    }
    printf("%d", k == n ? -1 : k);

    return 0;
}

