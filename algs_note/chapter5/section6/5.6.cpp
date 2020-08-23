//
// Created by zhang on 2020/8/23.
//
#include <cstdio>
#include "5.6.h"

int main() {
    char str1[1000], str2[1000];
    scanf("%s %s", str1, str2);
    bign a = change(str1);
    bign b = change(str2);
    print(add(a, b));
    return 0;
}