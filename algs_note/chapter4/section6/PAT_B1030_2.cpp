// 完美数列
// Created by zhang on 2020/8/21.
//
#include <cstdio>
#include <algorithm>

using namespace std;

const int manx = 100010;

int main() {
    int n, p, a[manx];
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int i = 0, j = 0, count = 1;
    while (i < n && j < n) {
        while (j < n && a[j] <= (long long) a[i] * p) {
            count = max(count, j - i + 1);
            j++;
        }
        i++;
    }
    printf("%d\n", count);
    return 0;
}