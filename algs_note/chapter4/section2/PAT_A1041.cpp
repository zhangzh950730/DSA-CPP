// Be Unique
// Created by zhang on 2020/8/18.
//

#include <cstdio>

int main() {
    int hashTable[10001] = {0}, A[100001];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        hashTable[A[i]]++;
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (hashTable[A[i]] == 1) {
            ans = A[i];
            break;
        }
    }
    if (ans == -1) printf("None\n");
    else printf("%d\n", ans);

    return 0;
}