// Êı×Ö·ÖÀà
// Created by zhang on 2020/8/13.
//

#include <cstdio>

int main() {
    int count[5] = {0};
    int ans[5] = {0};
    int n, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        if (temp % 5 == 0) { //A1
            if (temp % 2 == 0) {
                ans[0] += temp;
                count[0]++;
            }
        } else if (temp % 5 == 1) { //A2
            if (count[1] % 2 == 0) {
                ans[1] += temp;
            } else {
                ans[1] -= temp;
            }
            count[1]++;
        } else if (temp % 5 == 2) { //A3
            count[2]++;
        } else if (temp % 5 == 3) { //A4
            ans[3] += temp;
            count[3]++;
        } else {
            if (temp % 5 == 4) { //A5
                if (ans[4] < temp) {
                    ans[4] = temp;
                    count[4]++;
                }
            }
        }
    }

    if (count[0] == 0)printf("N ");
    else printf("%d ", ans[0]);

    if (count[1] == 0)printf("N ");
    else printf("%d ", ans[1]);

    if (count[2] == 0)printf("N ");
    else printf("%d ", count[2]);

    if (count[3] == 0)printf("N ");
    else printf("%.1f ", (double) ans[3] / count[3]);

    if (count[4] == 0)printf("N");
    else printf("%d", ans[4]);

    return 0;
}