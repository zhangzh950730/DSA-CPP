//
// Created by 张之豪 on 2021/11/22.
//

#include "stdio.h"
#include "string.h"

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);

void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int numcmp(char *, char *);

void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main(int argc, char *argv[]) {

}