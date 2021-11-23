//
// Created by 张之豪 on 2021/11/22.
//

#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int x = 1;
    int y = 2;
    swap(&x, &y);
    printf("x: %d\n", x);
    printf("y: %d\n", y);


}