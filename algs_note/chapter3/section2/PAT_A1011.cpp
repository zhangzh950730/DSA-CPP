// World Cup Betting
// Created by zhang on 2020/8/14.
//

#include <cstdio>

char S[3] = {'W', 'T', 'L'};

int main() {
    double a, maxTmp, res = 1.0;
    int maxIdx;
    for (int i = 0; i < 3; ++i) {
        maxIdx = -1;
        for (int j = 0; j < 3; ++j) {
            scanf("%lf", &a);
            if (maxTmp < a) {
                maxTmp = a;
                maxIdx = j;
            }
        }
        res *= maxTmp;
        printf("%c ", S[maxIdx]);
    }
    printf("%.2f", (res * 0.65 - 1) * 2);

    return 0;
}

