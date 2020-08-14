// Hello World for U
// Created by zhang on 2020/8/14.
//
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[100], ans[40][40];
    cin.getline(str, 100);
    int N = strlen(str);
    int n1 = (N + 2) / 3, n3 = n1, n2 = N + 2 - n1 - n3;
    // ³õÊ¼»¯
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            ans[i][j] = ' ';
        }
    }

    int pos = 0;
    for (int i = 1; i <= n1; ++i) { //n1
        ans[i][1] = str[pos++];
    }
    for (int i = 2; i <= n2; ++i) { //n2
        ans[n1][i] = str[pos++];
    }
    for (int i = n3 - 1; i >= 1; --i) { //n3
        ans[i][n2] = str[pos++];
    }

    //Êä³ö
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
