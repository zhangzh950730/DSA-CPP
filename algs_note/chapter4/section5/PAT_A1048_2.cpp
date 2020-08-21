// Find Coins
// Created by zhang on 2020/8/21.
//

#include <cstdio>
#include <algorithm>

using namespace std;

int a[100010];

int Bin(int left, int right, int x) {
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (a[mid] == x) return mid;
        else if (a[mid] > x) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main() {
    int n, m, i;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);

    for (i = 0; i < n; ++i) {
        int j = Bin(i, n - 1, m - a[i]);
        if (j != -1 && i != j) {
            printf("%d %d\n", a[i], a[j]);
            break;
        }
    }
    if (i == n) printf("No Solution\n");
    return 0;
}
