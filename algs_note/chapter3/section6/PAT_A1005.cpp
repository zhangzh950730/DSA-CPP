// Spell It Right
// Created by zhang on 2020/8/16.
//
#include <cstdio>
#include <cstring>

char num[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    char str[102];
    scanf("%s", str);
    int len = strlen(str), sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += str[i] - '0';
    }

    int digit[3], numL = 0;
    do {
        digit[numL++] = sum % 10;
        sum /= 10;
    } while (sum);

    for (int i = numL - 1; i >= 0; --i) {
        printf("%s", num[digit[i]]);
        if (i != 0) { printf(" "); }
    }
}