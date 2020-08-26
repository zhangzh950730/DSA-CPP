// ��������
// Created by zhang on 2020/8/25.
//

#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

// [0,12]�Ļ�����
string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                        "jly", "aug", "sep", "oct", "nov", "dec"};
// 13��[0,12]���Ļ�����
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes",
                       "hei", "elo", "syy", "lok", "mer", "jou"};
string numToStr[170];
map<string, int> strToNum;

void init() {
    for (int i = 0; i < 13; i++) {
        numToStr[i] = unitDigit[i];    // ��λΪ[0,12]��ʮλΪ0
        strToNum[unitDigit[i]] = i;
        numToStr[i * 13] = tenDigit[i];    // ʮλΪ[0,12]����λΪ0
        strToNum[tenDigit[i]] = i * 13;
    }
    for (int i = 1; i < 13; i++) {    // ʮλ
        for (int j = 1; j < 13; j++) {    // ��λ
            string str = tenDigit[i] + " " + unitDigit[j];    // ������
            numToStr[i * 13 + j] = str;    // ����->������
            strToNum[str] = i * 13 + j;    // ������->����
        }
    }
}

int main() {
    init();
    int T;
    scanf("%d%*c", &T);    // ��ѯ����
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