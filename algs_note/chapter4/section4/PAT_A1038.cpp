// Recover the Smallest Number
// Created by zhang on 2020/8/20.
//
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100001;
string str[maxn];

bool cmp(string a, string b) {
    return a + b < b + a;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    string ans;
    for (int i = 0; i < n; ++i) {
        ans += str[i];
    }
    while (!ans.empty() && ans[0] == '0') {
        ans.erase(ans.begin());
    }
    if (ans.empty()) cout << 0;
    else cout << ans;
    return 0;
}