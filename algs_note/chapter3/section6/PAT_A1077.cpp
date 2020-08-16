// Kuchiguse
// Created by zhang on 2020/8/16.
// 部分正确

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void reverse(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main() {
    int n, minLen = 256, count = 0;
    char str[100][256];

    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        cin.getline(str[i], sizeof(str[i]));
        reverse(str[i]);
        if (strlen(str[i]) < minLen) minLen = strlen(str[i]);
    }

    for (int i = 0; i < minLen; ++i) {
        char c = str[0][i];
        bool same = true;
        for (int j = 1; j < n; ++j) {
            if (str[j][i] != c) {
                same = false;
                break;
            }
        }
        if (same) count++;
        else break;
    }

    if (count) {
        for (int i = count - 1; i >= 0; --i) {
            printf("%c", str[0][i]);
        }
    } else {
        printf("nai");
    }
    return 0;
}