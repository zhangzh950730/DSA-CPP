//
// Created by zhang on 2020/9/27.
//
#include <iostream>

using namespace std;

int fact_do(int n) {
    int result = 1;
    do {
        result *= n;
        n = n - 1;
    } while (n > 1);
    return result;
}

int main() {
    int i = 0x7fffffff;
    cout << "32位 int最小值: " << i << endl;
    i = 0x7fffffff + 1;
    cout << "32位 int最大值: " << i << endl;

    int result = fact_do(13);
    cout << result << endl;
}