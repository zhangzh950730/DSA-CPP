//
// Created by 张之豪 on 2021/11/25.
//
#include <cstdlib>
#include <cstdio>

typedef struct {
    char *ch;
    int length;
} HString, String;


int StrLength(String S) {
    int i = 0;
    while (*(S.ch + i++));
    return --i;
}

void SubString(String &sub, String S, int start, int end) {
    char *p = sub.ch = (char *) malloc(sizeof(char));
    for (int i = 0; i < end; ++i) {
        *p = *(S.ch + i + start);
        p = p + 1;
    }
    sub.length = end;
}

int StrCompare(String S, String T) {
    if (S.length != T.length) return false;
    char *p = S.ch, *q = T.ch;
    for (int i = 0; i < S.length; ++i) {
        if (*p != *q) return 0;
        else {
            p = (p + 1);
            q = (q + 1);
        }
    }
    return 1;
}

int Index(String S, String T) {
    int i = 1, n = StrLength(S), m = StrLength(T);
    while (i < n - m + 1) {
        String sub;
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0) ++i;
        else return i;
    }
    return 0;
}


int main() {
    char ch[] = {'a', 'b', 'c', 'd'};
    String S = {ch, 4};
    int length = StrLength(S);
    printf("%d\n", length);


    char ch1[] = {'c', 'd'};
    String T = {ch1, 2};

    int compare = StrCompare(S, T);
    printf("compare: %d\n", compare);

    String sub;
    SubString(sub, S, 2, 2);

    compare = StrCompare(sub, T);
    printf("compare: %d\n", compare);
}
