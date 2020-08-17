//
// Created by zhang on 2020/8/17.
//

#include <cstdio>
#include <algorithm>

using namespace std;

struct Student {
    char name[11], id[11];
    int grade;
} stu[100];

bool cmp(Student a, Student b) {
    return a.grade > b.grade;
}

int main() {
    int n, left, right;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
    }
    sort(stu, stu + n, cmp);
    scanf("%d %d", &left, &right);

    bool none = true;
    for (int i = 0; i < n; ++i) {
        if (stu[i].grade >= left && stu[i].grade <= right) {
            printf("%s %s\n", stu[i].name, stu[i].id);
            none = false;
        }
    }
    if (none) printf("NONE\n");
    return 0;
}