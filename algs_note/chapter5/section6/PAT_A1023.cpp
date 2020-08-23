// Have Fun with Numbers
// Created by zhang on 2020/8/23.
//
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct bign {
    int d[1000];
    int len;

    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char str[]) {
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; ++i) {
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}

void print(bign a) {
    for (int i = a.len - 1; i >= 0; --i) {
        printf("%d", a.d[i]);
    }
}

bign multi(bign a, int b) {
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len; ++i) {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while (carry != 0) {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

bool judge(bign a, bign b) {
    if (a.len != b.len)return false;
    int count[10] = {0};
    for (int i = 0; i < a.len; ++i) {
        count[a.d[i]]++;
        count[b.d[i]]--;
    }
    for (int cnt : count) {
        if (cnt != 0) return false;
    }
    return true;
}

int main() {
    char str[21];
    cin.getline(str, 21);
    bign a = change(str);
    bign mul = multi(a, 2);
    if (judge(a, mul)) printf("Yes\n");
    else printf("No\n");
    print(mul);
    return 0;
}