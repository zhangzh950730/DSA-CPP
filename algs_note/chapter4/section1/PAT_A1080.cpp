// Graduate Admission
// Created by zhang on 2020/8/17.
//
#include <cstdio>
#include <algorithm>

using namespace std;
struct Student {
    int GE, GI, sum; //初试成绩,面试成绩,总成绩
    int r, stuId; // 排名,考生编号
    int cho[6]; //K个志愿学校编号
} stu[40010];

struct School {
    int quota; //招生人数额度
    int stuNum; //实际招生数
    int id[40010]; //招收的考生编号
    int lastAdmit; //记录最后一个招收的考生编号
} sch[110];

bool cmpStu(Student a, Student b) {
    if (a.sum != b.sum) return a.sum > b.sum;
    else return a.GE > b.GE;
}

bool cmpId(int a, int b) {
    return stu[a].stuId < stu[b].stuId;
}

int main() {
    int N, M, K; //考生数量,学校数量,每个考生的志愿数量
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; ++i) { //初始化学校
        scanf("%d", &sch[i].quota);
        sch[i].stuNum = 0;
        sch[i].lastAdmit - 1;
    }
    for (int i = 0; i < N; ++i) { //初始化考生
        scanf("%d %d", &stu[i].GE, &stu[i].GI);
        stu[i].sum = stu[i].GE + stu[i].GI;
        stu[i].stuId = i;
        for (int j = 0; j < K; ++j) {
            scanf("%d", &stu[i].cho[j]);
        }
    }

    sort(stu, stu + N, cmpStu); //排序考生
    for (int i = 0; i < N; ++i) { //计算排名
        if (i > 0 && stu[i].sum == stu[i - 1].sum && stu[i].GE == stu[i - 1].GE) {
            stu[i].r = stu[i - 1].r;
        } else {
            stu[i].r = i;
        }
    }

    for (int i = 0; i < N; ++i) { //计算录取情况
        for (int j = 0; j < K; ++j) {
            int choice = stu[i].cho[j];
            int num = sch[choice].stuNum;
            int last = sch[choice].lastAdmit;
            if (num < sch[choice].quota || (last != -1 && stu[i].r == stu[last].r)) {
                sch[choice].id[num] = i;
                sch[choice].stuNum++;
                sch[choice].lastAdmit = i;
                break;
            }
        }
    }

    for (int i = 0; i < M; ++i) {
        if (sch[i].stuNum > 0) {
            sort(sch[i].id, sch[i].id + sch[i].stuNum, cmpId);
            for (int j = 0; j < sch[i].stuNum; ++j) {
                printf("%d", stu[sch[i].id[j]].stuId);
                if (j < sch[i].stuNum - 1) printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}