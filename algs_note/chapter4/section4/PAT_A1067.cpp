// Sort with Swap(0, i)
// Created by zhang on 2020/8/20.
//
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXN = 100001;
int pos[MAXN];

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    int left = n - 1, num;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        pos[num] = i;
        if (num == i && num != 0) {
            left--;
        }
    }
    int k = 1; //��0���ⲻ�ڱ�λ����С��
    while (left > 0) {
        if (pos[0] == 0) {
            while (k < n) {
                if (pos[k] != k) {
                    swap(pos[0], pos[k]);
                    ans++;
                    break;
                }
                k++;
            }
        }
        while (pos[0] != 0) {
            swap(pos[0], pos[pos[0]]);
            ans++;
            left--;
        }
    }
    printf("%d\n", ans);
    return 0;
}