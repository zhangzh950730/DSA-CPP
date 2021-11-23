//
// Created by 张之豪 on 2021/11/22.
//
#include <stdio.h>

void strcpy1(char *s, char *t) {
    int i = 0;
    while ((s[i] = t[i]) != '\0') {
        i++;
    }
}

void strcpy2(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

void strcpy3(char *s, char *t) {
    while ((*s++ = *t++) != '\0');
}

void strcpy4(char *s, char *t) {
    while (*s++ = *t++);
}

int strcmp1(char *s, char *t) {
    int i;
    for (i = 0; s[i] == t[i]; ++i) {
        if (s[i] == '\0') return 0;
    }
    return s[i] - t[i];
}

int strcmp2(char *s, char *t) {
    for (; *s == *t; s++, t++) {
        if (*s != '\0') return 0;
    }
    return *s - *t;
}

int main() {
    char *pmessage;
    pmessage = "now is the time";

    char amessage[] = "now is the time";

    printf("pmessage: %s\n", pmessage);
    printf("amessage: %s\n", amessage);
}