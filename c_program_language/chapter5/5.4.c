//
// Created by 张之豪 on 2021/11/22.
//
#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else return 0;
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}

