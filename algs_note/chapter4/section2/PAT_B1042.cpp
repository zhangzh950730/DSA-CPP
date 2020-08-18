// ×Ö·ûÍ³¼Æ
// Created by zhang on 2020/8/18.
//

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int maxn = 1001;
    char str[maxn];
    int hashTable[26] = {0};
    cin.getline(str, maxn);
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') hashTable[str[i] - 'a']++;
        else if (str[i] >= 'A' && str[i] <= 'Z') hashTable[str[i] - 'A']++;
    }
    int max = 0;
    for (int i = 1; i < 26; ++i) {
        if (hashTable[i] > hashTable[max]) max = i;
    }
    printf("%c %d\n", 'a' + max, hashTable[max]);
    return 0;
}