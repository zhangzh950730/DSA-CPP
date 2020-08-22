// Elevator
// Created by zhang on 2020/8/22.
//

#include <cstdio>

int main() {
    int n, to, now = 0, total = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &to);
        if (to < now) {
            total += (now - to) * 4;
        } else {
            total += (to - now) * 6;
        }
        total += 5;
        now = to;
    }
    printf("%d", total);
    return 0;
}