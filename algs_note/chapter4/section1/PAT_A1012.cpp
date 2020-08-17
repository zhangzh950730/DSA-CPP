// The Best Rank
// Created by zhang on 2020/8/17.
//

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    int score[4];
} stu[2001];

char course[4] = {'A', 'C', 'M', 'E'};
int Rank[1000000][4] = {0}; //记录四门课的排名
int now;

bool cmp(Student a, Student b) {
    return a.score[now] > b.score[now];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
        stu[i].score[0] = round((stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0) + 0.5;
    }
    for (now = 0; now < 4; ++now) {
        sort(stu, stu + n, cmp);
        Rank[stu[0].id][now] = 1;
        for (int i = 1; i < n; ++i) {
            if (stu[i].score[now] == stu[i - 1].score[now]) {
                Rank[stu[i].id][now] = Rank[stu[i - 1].id][now];
            } else {
                Rank[stu[i].id][now] = i + 1;
            }
        }
    }
    int id;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &id);
        if (Rank[id][0] == 0) {
            printf("N/A\n");
        } else {
            int min = 0;
            for (int j = 1; j < 4; ++j) {
                if (Rank[id][j] < Rank[id][min]) {
                    min = j;
                }
            }
            printf("%d %c\n", Rank[id][min], course[min]);
        }
    }
    return 0;
}