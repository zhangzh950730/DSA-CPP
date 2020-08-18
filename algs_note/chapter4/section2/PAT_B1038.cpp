// 统计同成绩学生
// Created by zhang on 2020/8/18.
//

#include <cstdio>

int main() {
    int n, k, score[101] = {0}, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        score[temp]++;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &temp);
        printf("%d", score[temp]);
        if (i < k - 1) {
            printf(" ");
        }
    }
    return 0;
}

