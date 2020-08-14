// Boys vs Girls
// Created by zhang on 2020/8/14.
//

#include <cstdio>

struct person {
    char name[11];
    char id[11];
    int score;
} F, M, temp;

int main() {
    F.score = -1;
    M.score = 101;
    int n;
    char gender;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s %c %s %d", temp.name, &gender, temp.id, &temp.score);
        if (gender == 'M' && temp.score < M.score) {
            M = temp;
        }
        if (gender == 'F' && temp.score > F.score) {
            F = temp;
        }
    }

    if (F.score != -1) printf("%s %s\n", F.name, F.id);
    else printf("Absent\n");

    if (M.score != 101) printf("%s %s\n", M.name, M.id);
    else printf("Absent\n");

    if (F.score != -1 && M.score != 101) printf("%d\n", F.score - M.score);
    else printf("NA\n");
    return 0;
}

