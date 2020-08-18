// Graduate Admission
// Created by zhang on 2020/8/17.
//
#include <cstdio>
#include <algorithm>

using namespace std;
struct Student {
    int GE, GI, sum; //���Գɼ�,���Գɼ�,�ܳɼ�
    int r, stuId; // ����,�������
    int cho[6]; //K��־ԸѧУ���
} stu[40010];

struct School {
    int quota; //�����������
    int stuNum; //ʵ��������
    int id[40010]; //���յĿ������
    int lastAdmit; //��¼���һ�����յĿ������
} sch[110];

bool cmpStu(Student a, Student b) {
    if (a.sum != b.sum) return a.sum > b.sum;
    else return a.GE > b.GE;
}

bool cmpId(int a, int b) {
    return stu[a].stuId < stu[b].stuId;
}

int main() {
    int N, M, K; //��������,ѧУ����,ÿ��������־Ը����
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; ++i) { //��ʼ��ѧУ
        scanf("%d", &sch[i].quota);
        sch[i].stuNum = 0;
        sch[i].lastAdmit - 1;
    }
    for (int i = 0; i < N; ++i) { //��ʼ������
        scanf("%d %d", &stu[i].GE, &stu[i].GI);
        stu[i].sum = stu[i].GE + stu[i].GI;
        stu[i].stuId = i;
        for (int j = 0; j < K; ++j) {
            scanf("%d", &stu[i].cho[j]);
        }
    }

    sort(stu, stu + N, cmpStu); //������
    for (int i = 0; i < N; ++i) { //��������
        if (i > 0 && stu[i].sum == stu[i - 1].sum && stu[i].GE == stu[i - 1].GE) {
            stu[i].r = stu[i - 1].r;
        } else {
            stu[i].r = i;
        }
    }

    for (int i = 0; i < N; ++i) { //����¼ȡ���
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