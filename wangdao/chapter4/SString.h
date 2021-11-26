//
// Created by 张之豪 on 2021/11/26.
//
#define MAX_LEN  255

typedef struct {
    char ch[MAX_LEN];
    int length;
} SString;

int Index(SString S, SString T) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            i++, j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length) return i - T.length;
    else return 0;
}

size_t strlen(char *t) {

}

int match1(char *P, char *T) {
    size_t n = strlen(T), i = 0;
    size_t m = strlen(T), j = 0;
    while (j < m && i < n) {
        if (T[i] == P[j]) i++, j++;
        else i -= j - 1, j = 0;
    }
    return i - j;
}

int match2(char *P, char *T) {
    size_t n = strlen(T), i;
    size_t m = strlen(T), j;
    for (i = 0; i < n - m + 1; ++i) {
        for (j = 0; j < m; ++j)
            if (T[i + j] != P[j]) break;
        if (m <= j) break;
    }
    return i;
}

int *buildNext(char *P) {
    size_t m = strlen(P), j = 0; //主串指针
    int *N = new int[m]; //next表
    int t = N[0] = -1; //模式串指针
    while (j < m - 1) {
        // 匹配
        if (0 > t || P[j] == P[t]) N[++j] = ++t;
        // 失配
        else t = N[t];
    }
    return N;
}

int KMPMatch(char *P, char *T) {
    int *next = buildNext(P);
    int n = (int) strlen(T), i = 0;
    int m = (int) strlen(P), j = 0;
    while (j < m && i < n) {
        if (0 > j || T[i] == P[j]) i++, j++;
        else j = next[j];
    }
    delete[] next;
    return i - j;
}