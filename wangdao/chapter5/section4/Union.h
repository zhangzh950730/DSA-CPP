//
// Created by 张之豪 on 2021/12/1.
//
#define SIZE 100
int UFSets[SIZE];

void Initial(int S[]) {
    for (int i = 0; i < SIZE++i) {
        S[i] = -1;
    }
}

int find(int S[], int x) {
    while (S[x] >= 0) {
        x = S[x];
    }
    return x;
}

void Union(int S[], int Root1, int Root2) {
    S[Root2] = Root1;
}