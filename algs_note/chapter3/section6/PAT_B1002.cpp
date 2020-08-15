#include <cstdio>
#include <cstring>

// 写出这个数
// Created by zhang on 2020/8/15.
//

char change[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
    char str[101];
    scanf("%s", str);
    int sum = 0, len = strlen(str);
    for (int i = 0; i < len; ++i) {
        sum += str[i] - '0';
    }
    int num = 0, ans[3];
    do {
        ans[num++] = sum % 10;
        sum /= 10;
    } while (sum != 0);

    for (int i = num - 1; i >= 0; --i) {
        printf("%s", change[ans[i]]);
        if (i != 0) { printf(" "); }
        else printf("\n");
    }

    return 0;
}
