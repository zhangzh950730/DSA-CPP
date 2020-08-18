// ¾É¼üÅÌ
// Created by zhang on 2020/8/18.
//
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    bool HashTable[128] = {false};
    char str1[100], str2[100];
    cin.getline(str1, sizeof(str1));
    cin.getline(str2, sizeof(str2));
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (int i = 0; i < len1; ++i) {
        int j;
        char c1 = str1[i], c2;
        if (c1 >= 'a' && c1 <= 'z') c1 -= 32;
        for (j = 0; j < len2; ++j) {
            c2 = str2[j];
            if (c2 >= 'a' && c2 <= 'z') c2 -= 32;
            if (c1 == c2) break;
        }
        if (j == len2 && !HashTable[c1]) {
            printf("%c", c1);
            HashTable[c1] = true;
        } else {

        }
    }
    return 0;
}