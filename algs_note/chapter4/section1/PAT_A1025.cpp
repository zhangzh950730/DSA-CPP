// PAT Ranking
// Created by zhang on 2020/8/17.
//
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Student {
    char id[15];
    int score, location_number, location_rank;// 分数,考场号,考场排名
} stu[30010];

bool cmp(Student a, Student b) {
    if (a.score != b.score) return a.score > b.score;
    else return strcmp(a.id, b.id) < 0;
}

int main() {
    int n, k, num = 0; //考场数,每个考场考生数量,总考场数量
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) { //每个考场的信息
            scanf("%s %d", stu[num].id, &stu[num].score);
            stu[num].location_number = i;
            num++;
        }
        sort(stu + num - k, stu + num, cmp);
        stu[num - k].location_rank = 1;
        for (int j = num - k + 1; j < num; ++j) {
            if (stu[j].score == stu[j - 1].score) {
                stu[j].location_rank = stu[j - 1].location_rank;
            } else {
                stu[j].location_rank = j + 1 - (num - k);
            }
        }
    }
    printf("%d\n", num);
    sort(stu, stu + num, cmp);

    int r = 1;
    for (int i = 0; i < num; ++i) {
        if (i > 0 && stu[i].score != stu[i - 1].score) {
            r = i + 1;
        }
        printf("%s %d %d %d\n", stu[i].id, r, stu[i].location_number, stu[i].location_rank);
    }
    return 0;
}