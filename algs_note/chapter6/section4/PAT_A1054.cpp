//
// Created by zhang on 2020/8/26.
//

#include <cstdio>
#include <map>

using namespace std;

int main() {
    int n, m, col;
    map<int, int> count;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &col);
            if (count.find(col) != count.end()) count[col]++;
            else count[col] = 1;
        }
    }
    int k = 0, max = 0;
    for (auto &it : count) {
        if (it.second > max) {
            k = it.first;
            max = it.second;
        }
    }

    printf("%d\n", k);
    return 0;
}