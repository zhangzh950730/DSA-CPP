// ���°���һ����
// Created by zhang on 2020/8/14.
//

#include <cstdio>

int main() {
    // �� ��
    int row, col;
    char c;
    scanf("%d %c", &col, &c);

    if (col % 2) row = col / 2 + 1;
    else row = col / 2;

    // ��1��
    for (int i = 0; i < col; ++i) {
        printf("%c", c);
    }
    printf("\n");

    // ��2~row-1 ��
    for (int i = 2; i < row; ++i) {
        printf("%c", c);
        for (int j = 1; j < col - 1; ++j) {
            printf(" ");
        }
        printf("%c\n", c);
    }

    // ��row��
    for (int i = 0; i < col; ++i) {
        printf("%c", c);
    }
    printf("\n");

    return 0;
}

