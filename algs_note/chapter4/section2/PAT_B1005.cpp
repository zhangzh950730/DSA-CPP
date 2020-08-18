// ¼ÌĞø(3n+1)²ÂÏë
// Created by zhang on 2020/8/18.
//

#include <cstdio>
#include <algorithm>

using namespace std;

int cmp(int a, int b) {
    return a > b;
}

int main() {
    int k, A[101], temp;
    bool hashTable[100] = {false};
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &A[i]);
        temp = A[i];
        while (temp != 1) {
            if (temp % 2 == 0) temp /= 2;
            else temp = (temp * 3 + 1) / 2;
            if (temp <= 100)hashTable[temp] = true;
        }
    }
    bool first = true;
    sort(A, A + k, cmp);
    for (int i = 0; i < k; ++i) {
        if (!hashTable[A[i]]) {
            if (first) first = false;
            else printf(" ");
            printf("%d", A[i]);
        }
    }
    return 0;
}