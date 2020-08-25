// Are They Equal
// Created by zhang on 2020/8/25.
//
#include <iostream>
#include <string>

using namespace std;
int n;

string deal(string s, int &e) {
    int k = 0;
    while (s.length() > 0 && s[0] == '0') { //去掉前面的0
        s.erase(s.begin());
    }
    if (s[0] == '.') { //如果去掉0后面是小数点
        s.erase(s.begin()); //去掉小数点
        while (s.length() > 0 && s[0] == '0') {
            s.erase(s.begin()); //去掉小数点后非零位前所有的零
            e--; //每去掉一个0,指数e减一
        }
    } else { //若去掉前导零后不是小数点,则找到后面的小数点并删除
        while (k < s.length() && s[k] != '.') {
            k++;
            e++;
        }
        if (k < s.length()) { //while结束后 k<s.length(),则说明遇到了小数点
            s.erase(s.begin() + k); //把小数点删除
        }
    }

    if (s.length() == 0) { //特判原数为0
        e = 0;
    }
    int num = 0;
    k = 0;
    string res;
    while (num < n) { //精度还没到n
        if (k < s.length()) res += s[k++]; //存在数字,就加到res末尾
        else res += '0'; //否则res末尾添加0
        num++; //精度加一
    }
    return res;
}

int main() {
    string s1, s2, s3, s4;
    cin >> n >> s1 >> s2;
    int e1 = 0, e2 = 0;
    s3 = deal(s1, e1);
    s4 = deal(s2, e2);
    if (s3 == s4 && e1 == e2) {
        cout << "YES 0." << s3 << "*10^" << e1 << endl;
    } else {
        cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
    }
    return 0;
}
