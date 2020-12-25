//
// Created by zhang on 2020/9/17.
//

#include <cstdio>

int fun1(unsigned word) {
//    return (int) ((word << 24) >> 24);
    printf("%2x\n", word << 24);
    printf("%2x\n", (word << 24) >> 24);
    printf("%2x\n", (int) ((word << 24) >> 24));
    return 1;
}

int fun2(unsigned word) {
//    return ((int) word << 24) >> 24;
    printf("%2x\n", word << 24);
    printf("%2x\n", (int) word << 24);
    printf("%2x\n", ((int) word << 24) >> 24);
    return 1;
}

int main() {
    fun1(0x00000076);
    printf("%s\n", "---");
    fun2(0x00000076);
    printf("%s\n", "===");

    fun1(0x87654321);
    printf("%s\n", "---");
    fun2(0x87654321);
    printf("%s\n", "===");

    fun1(0x000000c9);
    printf("%s\n", "---");
    fun2(0x000000c9);
    printf("%s\n", "===");

    fun1(0xedcba987);
    printf("%s\n", "---");
    fun2(0xedcba987);
    printf("%s\n", "===");
}