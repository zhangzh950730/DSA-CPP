// 查验身份证
// Created by zhang on 2020/8/15.
//

#include <cstdio>

int w[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char change[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main() {
    int n;
    bool flag = true;
    char str[19];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int last = 0, j;
        scanf("%s", str);
        for (j = 0; j < 17; ++j) {
            if (str[j] < '0' || str[j] > '9') break;
            last += (str[j] - '0') * w[j];
        }
        if (j < 17) {
            flag = false;
            printf("%s\n", str);
        } else {
            if (change[last % 11] != str[17]) {
                flag = false;
                printf("%s\n", str);
            }
        }
    }

    if (flag) {
        printf("All passed");
    }
    return 0;
}