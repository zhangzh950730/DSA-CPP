//
// Created by zhang on 2020/12/25.
//
#include "ArrayList.h"

void deleteSame(ArrayList &L) {
    int j = 1;
    int same = L.data[0];
    for (int i = 1; i < L.length; ++i) {
        if (L.data[i] != same) {
            same = L.data[i];
            L.data[j++] = same;
        }
    }
    L.length = j;
}

int main() {
    int data[] = {1, 1, 1, 1, 2, 2, 3, 3};
    struct ArrayList L = {data, 8};
    deleteSame(L);

}
