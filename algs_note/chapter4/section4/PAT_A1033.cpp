// To Fill or Not to Fill
// Created by zhang on 2020/8/20.
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 510;
const int INF = 1000000000;

struct Station {
    double price, dis; //价格,与起点的距离
} st[MAX_N];

bool cmp(Station a, Station b) {
    return a.dis < b.dis;
}

int main() {
    int n;//加油站数量
    double Cmax, D, Davg; //最大油量,距离,单位油量支撑的距离
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf", &st[i].price, &st[i].dis);
    }
    st[n].price = 0;
    st[n].dis = D;
    sort(st, st + n, cmp);
    if (st[0].dis != 0) {
        printf("The maximum travel distance = 0.00\n");
    } else {
        int now = 0;// 当前所处的加油站位置
        // 总花费,当前油量以及满油行驶距离
        double ans = 0, nowTank = 0, MAX = Cmax * Davg;
        while (now < n) {
            int k = -1; //最低油价的加油站编号
            double priceMin = INF; //最低油价
            for (int i = now + 1; i <= n && st[i].dis - st[now].dis <= MAX; ++i) {
                if (st[i].price < priceMin) { //如果油价比当前油价低,更新最低油价
                    priceMin = st[i].price;
                    k = i;
                    if (priceMin < st[now].price) { //如果找到第一个油价低于当前油价的加油站,直接中断循环
                        break;
                    }
                }
            }
            if (k == -1) break; //满油状态下无法找到加油站
            // 为找到可达的加油站k,计算转移花费
            double need = (st[k].dis - st[now].dis) / Davg;
            if (priceMin < st[now].price) { //如果加油站k的油价低于当前油价
                // 只买足够到达加油站k的油
                if (nowTank < need) {
                    ans += (need - nowTank) * st[now].price;
                    nowTank = 0;
                } else {
                    nowTank -= need;
                }
            } else { //加油站k油价高于当前加油站
                ans += (Cmax - nowTank) * st[now].price;
                nowTank = Cmax - need;
            }
            now = k;
        }
        if (now == n) {
            printf("%.2f\n", ans);
        } else {
            printf("The maximum travel distance = %.2f\n", st[now].dis + MAX);
        }
    }
    return 0;
}