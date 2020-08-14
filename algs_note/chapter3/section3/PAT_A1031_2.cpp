// Hello World for U
// Created by zhang on 2020/8/14.
//
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[100];
    cin.getline(str, 100);
    int N = strlen(str);
    int n1 = (N + 2) / 3, n3 = n1, n2 = N + 2 - n1 - n3;
    // ≥ı ºªØ
    for (int i = 0; i < n1 - 1; ++i) {
        printf("%c", str[i]);
        for (int j = 0; j < n2 - 2; ++j) {
            printf(" ");
        }
        printf("%c\n", str[N - i - 1]);
    }
    for (int i = 0; i < n2; ++i) {
        printf("%c", str[n1 + i - 1]);
    }
    printf("\n");
    return 0;
}


