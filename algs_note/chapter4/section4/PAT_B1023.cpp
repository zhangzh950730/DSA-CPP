//  组个最小数
// Created by zhang on 2020/8/18.
//
#include <cstdio>

int main() {
    int count[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &count[i]);
    }
    for (int i = 1; i < 10; ++i) {
        if (count[i] > 0) {
            printf("%d", i);
            count[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; ++j) {
                printf("%d", i);
            }
        }
    }
    return 0;
}