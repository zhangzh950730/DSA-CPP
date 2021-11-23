//
// Created by 张之豪 on 2021/11/22.
//
#include "stdio.h"

char *month_name(int n) {
    static char *name[] = {
            "Illegal month",
            "January",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "September",
            "October",
            "November",
            "December"
    };
    return name[n];
}

int main() {
    char *name = month_name(2);
    printf("%s\n", name);
}
