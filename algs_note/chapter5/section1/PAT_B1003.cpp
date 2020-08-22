// 我要通过！
// Created by zhang on 2020/8/22.
//

#include <cstdio>
#include <cstring>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char str[101];
        scanf("%s", str);
        int len = strlen(str);
        int numP = 0, numT = 0, other = 0;
        int locP = -1, locT = -1;
        for (int i = 0; i < len; ++i) {
            if (str[i] == 'P') {
                numP++;
                locP = i;
            } else if (str[i] == 'T') {
                numT++;
                locT = i;
            } else if (str[i] != 'A') other++;
        }
        if (numP != 1 || numT != 1 || other != 0 || locT - locP <= 1) {
            printf("NO\n");
            continue;
        }

        int x = locP, y = locT - locP - 1, z = len - locT - 1;
        if (z - x * (y - 1) == x) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}