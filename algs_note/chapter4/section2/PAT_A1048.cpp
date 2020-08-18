// Find Coins
// Created by zhang on 2020/8/18.
//
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 1005;
int hashTable[N] = {0};

int main() {
    int n, m, temp;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        hashTable[temp]++;
    }
    for (int i = 0; i < m; ++i) {
        if (hashTable[i] > 0 && hashTable[m - i] > 0) {
            if (i == m - i && hashTable[i] < 2) {
                continue;
            }
            printf("%d %d", i, m - i);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
