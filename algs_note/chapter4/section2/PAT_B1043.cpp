// Êä³öPATest
// Created by zhang on 2020/8/18.
//
const int MAX_N = 10001;

#include <iostream>
#include <cstring>

using namespace std;

char test[6] = {'P', 'A', 'T', 'e', 's', 't'};
int count[6] = {0}, sum = 0;

int main() {
    char str[MAX_N];
    cin.getline(str, MAX_N);
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        char c = str[i];
        for (int j = 0; j < 6; ++j) {
            if (c == test[j]) {
                count[j]++;
                sum++;
            }
        }
    }

    while (sum > 0) {
        for (int i = 0; i < 6; ++i) {
            if (count[i] > 0) {
                count[i]--;
                sum--;
                printf("%c", test[i]);
            }
        }
    }
    return 0;
}