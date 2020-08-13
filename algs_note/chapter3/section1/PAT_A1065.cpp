// A+B and C(64bit)
// Created by zhang on 2020/8/13.
//

#include <cstdio>

int main() {
    int T, tcase = 1;
    scanf("%d", &T);
    long long a, b, c, res;
    bool flag;
    while (T--) {
        scanf("%lld%lld%lld", &a, &b, &c);
        res = a + b;
        if (a > 0 && b > 0 && res < 0) flag = true;
        else if (a < 0 && b < 0 && res >= 0) flag = false;
        else flag = res > c;
        printf("Case #%d: %s\n", tcase++, flag ? "true" : "false");
    }
    return 0;
}