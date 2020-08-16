// 数字加密
// Created by zhang on 2020/8/16.
//

#include <cstring>
#include <cstdio>

const int maxn = 101;
char A[maxn], B[maxn], ans[maxn] = {0};

void reverse(char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; ++i) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

int main() {
    scanf("%s%s", A, B);
    reverse(A);
    reverse(B);
    int lenA = strlen(A);
    int lenB = strlen(B);
    int len = lenA < lenB ? lenB : lenA;
    for (int i = 0; i < len; ++i) {
        int numA = i < lenA ? A[i] - '0' : 0;
        int numB = i < lenB ? B[i] - '0' : 0;
        if (i % 2 == 0) { //索引为0,但是为第一位,按照奇数处理
            int temp = (numA + numB) % 13;
            char c;
            if (temp == 10) {
                c = 'J';
            } else if (temp == 11) {
                c = 'Q';
            } else if (temp == 12) {
                c = 'K';
            } else {
                c = temp + '0';
            }
            ans[i] = c;
        } else {
            int temp = numB - numA;
            if (temp < 0) temp += 10;
            ans[i] = temp + '0';
        }
    }
    for (int i = len - 1; i >= 0; --i) {
        printf("%c", ans[i]);
    }
    printf("\n");
    return 0;
}

