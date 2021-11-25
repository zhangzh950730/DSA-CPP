//
// Created by 张之豪 on 2021/11/25.
//

#include <cstdio>

bool solution(char A[]) {
    int i = 0, j = 0;
    while (A[i] != '\0') {
        if (A[i] == 'I') {
            j++;
        } else if (A[i] == 'O') {
            j--;
            if (j < 0) {
                printf("序列非法\n");
                return false;
            }
        } else {
            printf("序列非法\n");
            return false;
        }

        i++;
    }
    if (j != 0) {
        printf("序列非法\n");
        return false;
    } else {
        printf("序列合法\n");
        return true;
    }

}