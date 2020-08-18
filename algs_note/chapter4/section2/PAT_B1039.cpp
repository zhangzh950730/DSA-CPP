// µ½µ×Âò²»Âò
// Created by zhang on 2020/8/18.
//

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 10001;
int hashTable[80] = {0}, miss = 0;

int change(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    if (c >= 'A' && c <= 'Z') return c - 'A' + 36;
    return -1;
}

int main() {
    char whole[maxn], target[maxn];
    cin.getline(whole, maxn);
    cin.getline(target, maxn);
    int len1 = strlen(whole);
    int len2 = strlen(target);
    for (int i = 0; i < len1; ++i) {
        hashTable[change(whole[i])]++;
    }
    for (int i = 0; i < len2; ++i) {
        int id = change(target[i]);
        hashTable[id]--;
        if (hashTable[id] < 0) miss++;
    }
    if (miss > 0) {
        printf("No %d", miss);
    } else {
        printf("Yes %d", len1 - len2);
    }
    return 0;
}