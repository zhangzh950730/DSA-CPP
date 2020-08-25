//
// Created by zhang on 2020/8/25.
//

#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<int> vi;
    for (int i = 1; i <= 5; ++i) {
        vi.push_back(i);
    }

    auto it = vi.begin();
    for (int i = 0; i < 5; ++i) {
        printf("%d ", *(it + i));
    }
    return 0;
}