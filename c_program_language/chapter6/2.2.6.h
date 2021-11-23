//
// Created by 张之豪 on 2021/11/22.
//

#ifndef DSA_CPP_6_H
#define DSA_CPP_6_H

#define NKEYS 10
#endif //DSA_CPP_6_H

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct key {
    char *word;
    int count;
} keytab[NKEYS];