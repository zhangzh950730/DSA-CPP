// A+BºÍC
// Created by zhang on 2020/8/13.
//

#include <cstdio>

int main() {
    int T, tcase = 1;
    long long A, B, C;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld %lld", &A, &B, &C);
        printf("Case #%d: %s\n", tcase++, (A + B > C) ? "true" : "false");
    }
    return 0;
}

