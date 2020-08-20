// PAT Judge
// Created by zhang on 2020/8/17.
//
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAX_N = 100010;

struct Student {
    int id; //准考证号
    int score[6]; //每道题的得分
    bool flag; //是否有能通过编译的提交
    int score_all; //总分
    int solve; //完美解题数
} stu[MAX_N];

bool cmp(Student a, Student b) {
    if (a.flag != b.flag) return a.flag > b.flag;
    else if (a.score_all != b.score_all) return a.score_all > b.score_all;
    else if (a.solve != b.solve) return a.solve > b.solve;
    return a.id < b.id;
}

int main() {
    int n, k, m; // 考生数,题目数,提交数
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= n; ++i) { //初始化考生
        stu[i].id = i;
        stu[i].score_all = 0;
        stu[i].solve = 0;
        stu[i].flag = false;
        memset(stu[i].score, -1, sizeof(stu[i].score));
    }
    int full[k];
    for (int i = 1; i <= k; ++i) { //记录每题的满分
        scanf("%d", &full[i]);
    }
    int uid, pid, score;
    for (int i = 0; i < m; ++i) { //提交记录
        scanf("%d %d %d", &uid, &pid, &score);
        if (score != -1) { //不是编译错误,则有过能通过编译的题
            stu[uid].flag = true;
        }
        if (score == -1 && stu[uid].score[pid] == -1) { //第一次编译错误,记为0
            stu[uid].score[pid] = 0;
        }
        if (score == full[pid] && stu[uid].score[pid] < full[pid]) { //某题首次出现满分,完美解题数加一
            stu[uid].solve++;
        }
        if (score > stu[uid].score[pid]) { //如果某题获得更高分值,则覆盖
            stu[uid].score[pid] = score;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (stu[i].score[j] != -1) {
                stu[i].score_all += stu[i].score[j];
            }
        }
    }
    sort(stu + 1, stu + n + 1, cmp);
    int r = 1;
    for (int i = 1; i <= n && stu[i].flag; ++i) {
        if (i > 1 && stu[i].score_all != stu[i - 1].score_all) {
            r = i;
        }
        printf("%d %05d %d", r, stu[i].id, stu[i].score_all);
        for (int j = 1; j <= k; ++j) {
            if (stu[i].score[j] == -1) {
                printf(" -");
            } else {
                printf(" %d", stu[i].score[j]);
            }
        }
        printf("\n");
    }
    return 0;
}