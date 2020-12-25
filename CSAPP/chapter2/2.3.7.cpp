//
// Created by zhang on 2020/9/22.
//
#include <cstdio>

int div16(int x) {
    int bias = (x >> 31) & 0xf;
    return (x + bias) >> 4;
}

int main() {
    int result = div16(-64);
    printf("%d", result);
    return 0;
}