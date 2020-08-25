// Student List for Course
// Created by zhang on 2020/8/25.
//
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 40001;
const int maxc = 2501;

char name[maxn][5];
vector<int> course[maxc];

bool cmp(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}

int main() {
    int n, k, c, courseId;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s %d", name[i], &c);
        for (int j = 0; j < c; ++j) {
            scanf("%d", &courseId);
            course[courseId].push_back(i);
        }
    }

    for (int i = 1; i <= k; ++i) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);
        for (int j : course[i]) {
            printf("%s\n", name[j]);
        }
    }
    return 0;
}