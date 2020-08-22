// ÓÐ¼¸¸öPAT
// Created by zhang on 2020/8/21.
//
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 100010;
const int MOD = 1000000007;
char str[MAX_N];
int leftNumP[MAX_N] = {0};

int main() {
    cin.getline(str, MAX_N);
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        if (i > 0) leftNumP[i] = leftNumP[i - 1];
        if (str[i] == 'P') leftNumP[i]++;
    }
    int ans = 0, rightNumT = 0;
    for (int i = len - 1; i >= 0; --i) {
        if (str[i] == 'T') {
            rightNumT++;
        } else if (str[i] == 'A') {
            ans = (ans + leftNumP[i] * rightNumT) % MOD;
        }
    }
    printf("%d\n", ans);
    return 0;
}