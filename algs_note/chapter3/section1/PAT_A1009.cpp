// Product of Polynomials
// Created by zhang on 2020/8/14.
//

#include <cstdio>

struct Poly {
    int exp;//指数
    double cof;//系数
} ploy[1001];

double ans[2001];

int main() {
    int n, m, count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %lf", &ploy[i].exp, &ploy[i].cof);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int exp;
        double cof;
        scanf("%d %lf", &exp, &cof);
        for (int j = 0; j < n; ++j) {
            ans[ploy[j].exp + exp] += ploy[j].cof * cof;
        }
    }
    for (int i = 0; i < 2001; ++i) {
        if (ans[i] != 0.0) { count++; }
    }
    printf("%d", count);

    for (int i = 2000; i >= 0; --i) {
        if (ans[i] != 0.0) { printf(" %d %.1f", i, ans[i]); }
    }
    return 0;
}