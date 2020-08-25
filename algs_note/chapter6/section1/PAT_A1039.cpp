// Course List for Student
// Created by zhang on 2020/8/25.
//

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 40010;
const int M = 26 * 26 * 26 * 10;
vector<int> selectCourse[M];

int getId(char name[5]) {
    int id = 0;
    for (int i = 0; i < 3; ++i) {
        id = id * 26 + (name[i] - 'A');
    }
    id = id * 10 + (name[3] - '0');
    return id;
}

int main() {
    char name[5];
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; ++i) {
        int course, x;
        scanf("%d %d", &course, &x);
        for (int j = 0; j < x; ++j) {
            scanf("%s", name);
            int id = getId(name);
            selectCourse[id].push_back(course);
        }
    }

    for (int i = 0; i < n; ++i) {
        scanf("%s", name);
        int id = getId(name);
        sort(selectCourse[id].begin(), selectCourse[id].end());
        printf("%s %d", name, selectCourse[id].size());
        for (int j : selectCourse[id]) {
            printf(" %d", j);
        }
        printf("\n");
    }
    return 0;
}