//
// Created by 张之豪 on 2021/11/22.
//
#include <stdio.h>

int strlen(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++) {
        n++;
    }
    return n;
}

int main() {
    int n = strlen("hello, world");
    printf("n : %d\n", n);

    int a[5] = {1, 2, 3, 4, 5};
    int *pa;
    printf("a: %d\n", *a);
    printf("a+1: %d\n", *a + 1);
    printf("a+2: %d\n", a[2]);

    pa = &a[0];
    printf("pa: %d\n", *pa);

    int x = *pa;
    printf("x: %d\n", x);


}