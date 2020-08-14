// ÈË¿ÚÆÕ²é
// Created by zhang on 2020/8/14.
//

#include <cstdio>

struct Person {
    char name[6];
    int yy, mm, dd;
} oldset, youngeset, left, right, temp;

bool lessEqu(Person a, Person b) {
    if (a.yy != b.yy) {
        return a.yy <= b.yy;
    } else if (a.mm != b.mm) {
        return a.mm <= b.mm;
    } else {
        return a.dd <= b.dd;
    }
}

bool moreEqu(Person a, Person b) {
    if (a.yy != b.yy) {
        return a.yy >= b.yy;
    } else if (a.mm != b.mm) {
        return a.mm >= b.mm;
    } else {
        return a.dd >= b.dd;
    }
}

void init() {
    youngeset.yy = left.yy = 1814;
    oldset.yy = right.yy = 2014;
    youngeset.mm = oldset.mm = right.mm = left.mm = 9;
    youngeset.dd = oldset.dd = right.dd = left.dd = 6;
}

int main() {
    init();
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s %d/%d/%d", temp.name, &temp.yy, &temp.mm, &temp.dd);
        if (lessEqu(temp, right) && moreEqu(temp, left)) {
            count++;
            if (moreEqu(temp, youngeset)) { youngeset = temp; }
            if (lessEqu(temp, oldset)) { oldset = temp; }
        }
    }
    if (count == 0) printf("0\n");
    else printf("%d %s %s", count, oldset.name, youngeset.name);
    return 0;
}

