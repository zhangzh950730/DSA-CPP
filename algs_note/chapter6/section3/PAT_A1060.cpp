// Are They Equal
// Created by zhang on 2020/8/25.
//
#include <iostream>
#include <string>

using namespace std;
int n;

string deal(string s, int &e) {
    int k = 0;
    while (s.length() > 0 && s[0] == '0') { //ȥ��ǰ���0
        s.erase(s.begin());
    }
    if (s[0] == '.') { //���ȥ��0������С����
        s.erase(s.begin()); //ȥ��С����
        while (s.length() > 0 && s[0] == '0') {
            s.erase(s.begin()); //ȥ��С��������λǰ���е���
            e--; //ÿȥ��һ��0,ָ��e��һ
        }
    } else { //��ȥ��ǰ�������С����,���ҵ������С���㲢ɾ��
        while (k < s.length() && s[k] != '.') {
            k++;
            e++;
        }
        if (k < s.length()) { //while������ data<s.length(),��˵��������С����
            s.erase(s.begin() + k); //��С����ɾ��
        }
    }

    if (s.length() == 0) { //����ԭ��Ϊ0
        e = 0;
    }
    int num = 0;
    k = 0;
    string res;
    while (num < n) { //���Ȼ�û��n
        if (k < s.length()) res += s[k++]; //��������,�ͼӵ�resĩβ
        else res += '0'; //����resĩβ���0
        num++; //���ȼ�һ
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
