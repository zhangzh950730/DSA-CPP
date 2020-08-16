// Password
// Created by zhang on 2020/8/16.
//

#include <cstring>
#include <cstdio>

struct node {
    char name[20], password[20];
    bool isChange;
} T[1005];

void crypt(node &t, int &count) {
    int len = strlen(t.password);
    for (int i = 0; i < len; ++i) {
        if (t.password[i] == '1') {
            t.password[i] = '@';
            t.isChange = true;
        } else if (t.password[i] == '0') {
            t.password[i] = '%';
            t.isChange = true;
        } else if (t.password[i] == 'l') {
            t.password[i] = 'L';
            t.isChange = true;
        } else if (t.password[i] == 'O') {
            t.password[i] = 'o';
            t.isChange = true;
        }
    }
    if (t.isChange) {
        count++;
    }
}

int main() {
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s %s", T[i].name, T[i].password);
        T[i].isChange = false;
        crypt(T[i], count);
    }

    if (count == 0) {
        if (n == 1) {
            printf("There is 1 account and no account is modified");
        } else {
            printf("There are %d accounts and no account is modified", n);
        }
    } else {
        printf("%d\n", count);
        for (int i = 0; i < n; ++i) {
            if (T[i].isChange) {
                printf("%s %s\n", T[i].name, T[i].password);
            }
        }
    }
    return 0;
}