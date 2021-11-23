//
// Created by 张之豪 on 2021/11/22.
//

#include "stdio.h"

int main() {
    int x = 1, y = 0, z[10];
    int *ip;
    ip = &x;
    printf("ip: %d\n", *ip);
    y = *ip;
    printf("y: %d\n", y);
    *ip = 0;
    printf("ip: %d\n", *ip);
    ip = &z[0];
    printf("ip: %d\n", *ip);

    *ip = *ip + 10;
    printf("ip: %d\n", *ip);

}