// To Fill or Not to Fill
// Created by zhang on 2020/8/20.
//

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 510;
const int INF = 1000000000;

struct Station {
    double price, dis; //�۸�,�����ľ���
} st[MAX_N];

bool cmp(Station a, Station b) {
    return a.dis < b.dis;
}

int main() {
    int n;//����վ����
    double Cmax, D, Davg; //�������,����,��λ����֧�ŵľ���
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
        int now = 0;// ��ǰ�����ļ���վλ��
        // �ܻ���,��ǰ�����Լ�������ʻ����
        double ans = 0, nowTank = 0, MAX = Cmax * Davg;
        while (now < n) {
            int k = -1; //����ͼ۵ļ���վ���
            double priceMin = INF; //����ͼ�
            for (int i = now + 1; i <= n && st[i].dis - st[now].dis <= MAX; ++i) {
                if (st[i].price < priceMin) { //����ͼ۱ȵ�ǰ�ͼ۵�,��������ͼ�
                    priceMin = st[i].price;
                    k = i;
                    if (priceMin < st[now].price) { //����ҵ���һ���ͼ۵��ڵ�ǰ�ͼ۵ļ���վ,ֱ���ж�ѭ��
                        break;
                    }
                }
            }
            if (k == -1) break; //����״̬���޷��ҵ�����վ
            // Ϊ�ҵ��ɴ�ļ���վk,����ת�ƻ���
            double need = (st[k].dis - st[now].dis) / Davg;
            if (priceMin < st[now].price) { //�������վk���ͼ۵��ڵ�ǰ�ͼ�
                // ֻ���㹻�������վk����
                if (nowTank < need) {
                    ans += (need - nowTank) * st[now].price;
                    nowTank = 0;
                } else {
                    nowTank -= need;
                }
            } else { //����վk�ͼ۸��ڵ�ǰ����վ
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