//
// Created by zhang on 2020/8/12.
//

#include <stdio.h>

void change(int *p) {
    *p = 233;
}

void change(int &p) {
    p = 233;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
//    int a = 1;
//    printf("%d,%d\n", &a, a);

//    int *p = &a;
//    printf("%d,%d\n", *p, p);

//    int a[10] = {1, 3, 5};
//    int *p = a;
//    printf("%d\n", *p);

//    int a[10];
//    for (int i = 0; i < 10; ++i) {
//        scanf("%d", a + i);
//    }
//    for (int i = 0; i < 10; ++i) {
//        printf("%d ", *(a + i));
//    }

//    int a[10] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
//    for (int *p = a; p < a + 10; p++) {
//        printf("%d ", *p);
//    }

    int a = 1;
    change(&a);
    printf("%d", a);

    int b = 1;
    change(b);
    printf("%d", b);


//    int a = 1;
//    int b = 2;
//    exchange1(&a, &b);
//    printf("a = %d, b = %d", a, b);



    return 0;
}



