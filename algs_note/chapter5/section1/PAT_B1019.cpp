// Êý×ÖºÚ¶´
// Created by zhang on 2020/8/22.
//

#include <cstdio>
#include <algorithm>

using namespace std;

void toArray(int n, int num[]) {
    for (int i = 0; i < 4; ++i) {
        num[i] = n % 10;
        n /= 10;
    }
}

int toNumber(int num[]) {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum = sum * 10 + num[i];
    }
    return sum;
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, MAX, MIN, num[5];
    scanf("%d", &n);

    while (true) {
        toArray(n, num);
        sort(num, num + 4);
        MIN = toNumber(num);
        sort(num, num + 4, cmp);
        MAX = toNumber(num);
        n = MAX - MIN;
        printf("%04d - %04d = %04d\n", MAX, MIN, n);
        if (n == 0 || n == 6174) break;
    }
}

