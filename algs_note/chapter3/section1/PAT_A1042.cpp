// Shuffling Machine
// Created by zhang on 2020/8/13.
//

#include <cstdio>

const int N = 54;
char mp[5] = {'S', 'H', 'C', 'D', 'J'};
int start[N + 1], end[N + 1], next[N + 1];

int main() {
    int K;
    scanf("%d", &K);
    for (int i = 1; i <= N; ++i) {
        start[i] = i; //初始化编号
        scanf("%d", &next[i]); //要求的编号
    }

    // 执行K次洗牌操作
    for (int step = 0; step < K; ++step) {
        // 移动到指定位置
        for (int i = 1; i <= N; ++i) {
            end[next[i]] = start[i];
        }
        // 重置start数组,便于下次洗牌
        for (int i = 1; i <= N; ++i) {
            start[i] = end[i];
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (i != 1) printf(" ");
        start[i]--;
        printf("%c%d", mp[start[i] / 13], start[i] % 13 + 1);
    }
    return 0;
}