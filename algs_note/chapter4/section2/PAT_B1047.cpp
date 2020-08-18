// 编程团体赛
// Created by zhang on 2020/8/18.
//
#include <cstdio>

int ans[1001] = {0};

int main() {
    int N, team, member, score;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d-%d %d", &team, &member, &score);
        ans[team] += score;
    }
    int max = 0;
    for (int i = 1; i < 1001; ++i) {
        if (ans[i] > ans[max]) max = i;
    }
    printf("%d %d\n", max, ans[max]);
    return 0;
}