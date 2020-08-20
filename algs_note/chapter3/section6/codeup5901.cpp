// »ØÎÄ´®
// Created by zhang on 2020/8/14.
//

#include <cstring>
#include <cstdio>

const int MAX_N = 256;

bool judge(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - 1 - i]) { return false; }
    }
    return true;
}

int main() {
    char str[MAX_N];
    while (gets(str)) {
        printf("%s\n", judge(str) ? "YES" : "NO");
    }
    return 0;
}

