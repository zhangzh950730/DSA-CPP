// 换个格式输出整数
// Created by zhang on 2020/8/15.
//

#include <cstdio>

int main() {
    int n, ans[3], num = 0;
    scanf("%d", &n);
    do {
        ans[num++] = n % 10;
        n /= 10;
    } while (n != 0);

    for (int i = num - 1; i >= 0; --i) {
        if (i == 2) {
            for (int j = 0; j < ans[i]; ++j) {
                printf("B");
            }
        }
        if (i == 1) {
            for (int j = 0; j < ans[i]; ++j) {
                printf("S");
            }
        }
        if (i == 0) {
            for (int j = 1; j <= ans[i]; ++j) {
                printf("%d", j);
            }
        }
    }
    printf("\n");
    return 0;
}