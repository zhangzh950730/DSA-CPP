// 在霍格沃兹找零钱
// Created by zhang on 2020/8/15.
//

#include <cstdio>

const int Galleon = 17 * 29;
const int Sickle = 29;

int main() {
    int a1, a2, a3, b1, b2, b3;
    scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
    int price = a1 * Galleon + a2 * Sickle + a3; //应付款
    int money = b1 * Galleon + b2 * Sickle + b3; //实付款
    int change = money - price;
    if (change < 0) {
        change = -change;
        printf("-");
    }
    printf("%d.%d.%d\n", change / Galleon, change % Galleon / Sickle, change % Sickle);
    return 0;
}