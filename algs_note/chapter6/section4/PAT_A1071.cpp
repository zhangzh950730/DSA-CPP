// Speech Patterns
// Created by zhang on 2020/8/26.
//
#include <map>
#include <iostream>

using namespace std;

bool check(char c) {
    return (c >= '0' && c <= '9')
           || (c >= 'A' && c <= 'Z')
           || (c >= 'a' && c <= 'z');
}

int main() {
    map<string, int> count;
    string str;
    getline(cin, str);
    int i = 0;
    while (i < str.length()) {
        string word;
        while (i < str.length() && check(str[i])) { //合法字符累加到单词中
            if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32; //大写字符转化为小写
            word += str[i++];
        }
        if (!word.empty()) { //当前单词不为空,计入count
            if (count.find(word) == count.end()) count[word] = 1;
            else count[word]++;
        }
        while (i < str.length() && !check(str[i])) i++; //跳过非单词字符
    }
    string ans;
    int max = 0;
    for (auto &it :count) {
        if (it.second > max) {
            ans = it.first;
            max = it.second;
        }
    }
    cout << ans << " " << max << endl;
    return 0;
}