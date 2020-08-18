// 月饼
// Created by zhang on 2020/8/18.
//
#include <cstdio>
#include <algorithm>

using namespace std;

struct MoonCake {
    double store; //库存
    double sell; //总售价
    double price; //单价
} cake[1000];

int cmp(MoonCake a, MoonCake b) {
    return a.price > b.price;
}

int main() {
    int N;
    double D;
    scanf("%d %lf", &N, &D);
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &cake[i].store);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &cake[i].sell);
        cake[i].price = cake[i].sell / cake[i].store;
    }
    sort(cake, cake + N, cmp);
    double ans = 0.0;
    for (int i = 0; i < N; ++i) {
        if (cake[i].store <= D) {
            ans += cake[i].sell;
            D -= cake[i].store;
        } else {
            ans += cake[i].price * D;
            break;
        }
    }
    printf("%.2f\n", ans);

    return 0;
}