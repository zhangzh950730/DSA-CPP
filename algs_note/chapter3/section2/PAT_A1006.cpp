// Sign In and Sign out
// Created by zhang on 2020/8/14.
//

#include <cstdio>

struct Sign {
    char id_number[16];
    int yy, mm, dd;
} temp, in, out;

bool great(Sign sign1, Sign sign2) {
    if (sign1.yy != sign2.yy) {
        return sign1.yy > sign2.yy;
    } else if (sign1.mm != sign2.mm) {
        return sign1.mm > sign2.mm;
    } else {
        return sign1.dd > sign2.dd;
    }
}

int main() {
    out.yy = 0, out.mm = 0, out.dd = 0;
    in.yy = 23, in.mm = 59, in.dd = 59;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        // 先读入签到时间
        scanf("%s %d:%d:%d", temp.id_number, &temp.yy, &temp.mm, &temp.dd);
        if (great(in, temp)) {
            in = temp;
        }
        // 再读入签退时间
        scanf("%d:%d:%d", &temp.yy, &temp.mm, &temp.dd);
        if (great(temp, out)) {
            out = temp;
        }
    }
    printf("%s %s", in.id_number, out.id_number);
    return 0;
}

