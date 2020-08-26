// 火星数字
// Created by zhang on 2020/8/25.
//

#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

// [0,12]的火星文
string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                        "jly", "aug", "sep", "oct", "nov", "dec"};
// 13的[0,12]倍的火星文
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes",
                       "hei", "elo", "syy", "lok", "mer", "jou"};
string numToStr[170];
map<string, int> strToNum;

void init() {
    for (int i = 0; i < 13; i++) {
        numToStr[i] = unitDigit[i];    // 个位为[0,12]，十位为0
        strToNum[unitDigit[i]] = i;
        numToStr[i * 13] = tenDigit[i];    // 十位为[0,12]，个位为0
        strToNum[tenDigit[i]] = i * 13;
    }
    for (int i = 1; i < 13; i++) {    // 十位
        for (int j = 1; j < 13; j++) {    // 个位
            string str = tenDigit[i] + " " + unitDigit[j];    // 火星文
            numToStr[i * 13 + j] = str;    // 数字->火星文
            strToNum[str] = i * 13 + j;    // 火星文->数字
        }
    }
}

int main() {
    init();
    int T;
    scanf("%d%*c", &T);    // 查询个数
    while (T--) {
        string str;
        getline(cin, str);
        if (str[0] >= '0' && str[0] <= '9') {
            int num = 0;
            for (char c : str) {
                num = num * 10 + (c - '0');
            }
            cout << numToStr[num] << endl;
        } else {
            cout << strToNum[str] << endl;
        }
    }
    return 0;
}