// ¾É¼üÅÌ´ò×Ö
// Created by zhang on 2020/8/18.
//
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 100000;
bool hashTable[256];
char str[maxn];

int main() {
    memset(hashTable, true, sizeof(hashTable));
    cin.getline(str, maxn);
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
        hashTable[str[i]] = false;
    }

    cin.getline(str, maxn);
    len = strlen(str);
    for (int i = 0; i < len; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            int low = str[i] - 'A' + 'a';
            if (hashTable[low] && hashTable['+']) {
                printf("%c", str[i]);
            }
        } else if (hashTable[str[i]]) {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}