// 一元多项式求导
// Created by zhang on 2020/8/13.
//

#include <cstdio>

int main() {
    int a[1010] = {0};
    int k, e, count = 0; //k为系数,e为指数,count计数不为零的导数项个数
    while (scanf("%d%d", &k, &e) != EOF) {
        a[e] = k;
    }
    a[0] = 0;
    for (int i = 1; i <= 1000; ++i) {
        a[i - 1] = a[i] * i;
        a[i] = 0;
        if (a[i - 1] != 0) count++;
    }
    if (count == 0) { printf("0 0"); }
    else {
        for (int i = 1000; i >= 0; --i) {
            if (a[i] != 0) {
                printf("%d %d", a[i], i);
                count--;
                if (count != 0) { printf(" "); }
            }
        }
    }
    return 0;
}
