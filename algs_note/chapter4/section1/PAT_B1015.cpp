// 德才论
// Created by zhang on 2020/8/17.
//

#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Student {
    char id[10];
    int de, cai, sum;
    int level;
} stu[100001];

bool cmp(Student a, Student b) {
    if (a.level != b.level) return a.level < b.level;
    else if (a.sum != b.sum) return a.sum > b.sum;
    else if (a.de != b.de) return a.de > b.de;
    else return strcmp(a.id, b.id) < 0;
}

int main() {
    int N, L, H;
    scanf("%d%d%d", &N, &L, &H);
    int m = N;// 及格人数
    for (int i = 0; i < N; ++i) {
        scanf("%s%d%d", &stu[i].id, &stu[i].de, &stu[i].cai);
        int de = stu[i].de;
        int cai = stu[i].cai;
        stu[i].sum = de + cai;
        if (de < L || cai < L) {
            stu[i].level = 5;
            m--;
        } else if (de >= H && cai >= H) stu[i].level = 1;
        else if (de >= H && cai < H) stu[i].level = 2;
        else if (de >= cai) stu[i].level = 3;
        else stu[i].level = 4;
    }
    sort(stu, stu + N, cmp);
    printf("%d\n", m);
    for (int i = 0; i < m; ++i) {
        if (stu[i].level != 5) {
            printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
        }
    }
}