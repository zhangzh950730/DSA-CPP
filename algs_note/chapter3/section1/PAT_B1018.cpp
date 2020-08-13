// 锤子剪刀布
// Created by zhang on 2020/8/13.
//

#include <cstdio>

int change(char c) {
    if (c == 'B') return 0;
    if (c == 'C') return 1;
    if (c == 'J') return 2;
    return -1;
}

int main() {
    char mp[3] = {'B', 'C', 'J'};
    int n;
    scanf("%d", &n);

    int times_A[3] = {0}, times_B[3] = {0}; // 记录甲乙的胜平负次数
    int hand_A[3] = {0}, hand_B[3] = {0}; // 记录甲乙3种手势的获胜次数
    char c1, c2;
    int k1, k2;

    for (int i = 0; i < n; ++i) {
        getchar();
        scanf("%c %c", &c1, &c2);
        k1 = change(c1);
        k2 = change(c2);

        if ((k1 + 1) % 3 == k2) { //甲获胜
            times_A[0]++;
            times_B[2]++;
            hand_A[k1]++;
        }
        if (k1 == k2) { //平局
            times_A[1]++;
            times_B[1]++;
        }
        if ((k2 + 1) % 3 == k1) { //乙获胜
            times_B[0]++;
            times_A[2]++;
            hand_B[k2]++;
        }
    }
    printf("%d %d %d\n", times_A[0], times_A[1], times_A[2]);
    printf("%d %d %d\n", times_B[0], times_B[1], times_B[2]);

    int idA = 0, idB = 0;
    for (int i = 0; i < 3; ++i) {
        if (hand_A[idA] < hand_A[i]) idA = i;
        if (hand_B[idB] < hand_B[i]) idB = i;
    }
    printf("%c %c\n", mp[idA], mp[idB]);

    return 0;
}