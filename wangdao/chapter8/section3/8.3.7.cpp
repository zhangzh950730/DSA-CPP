//
// Created by 张之豪 on 2021/12/14.
//
#include "8.3.h"

typedef enum {
    RED, WHITE, BLUE
} color;

void flagArrange(color a[], int n) {
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
        switch (a[j]) {
            case RED:
                swap(a[i++], a[j++]);
                break;
            case WHITE:
                j++;
                break;
            case BLUE:
                swap(a[j], a[k--]);
                break;
        }
    }
}
