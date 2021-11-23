//
// Created by 张之豪 on 2021/11/22.
//
#include "stdio.h"
#include "2.2.6.h"

#define XMAX 100

struct point makepoint(int x, int y) {
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

int main() {
    struct rect screen;
    struct point middle;

    screen.pt1 = makepoint(20, 50);
    screen.pt2 = makepoint(XMAX, XMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2);
    printf("middle.x = %d; middle.y =  %d\n", middle.x, middle.y);

    printf("pt1.x = %d; pt1.y =  %d\n", screen.pt1.x, screen.pt1.y);
    struct point pt11 = addpoint(screen.pt1, screen.pt2);
    printf("pt11.x = %d; pt11.y =  %d\n", pt11.x, pt11.y);
    printf("pt1.x = %d; pt1.y =  %d\n", screen.pt1.x, screen.pt1.y);


}