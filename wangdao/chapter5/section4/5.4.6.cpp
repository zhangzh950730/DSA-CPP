//
// Created by 张之豪 on 2021/12/1.
//

#include "CSNode.h"

int Height(CSTree bt) {
    if (bt == nullptr) {
        return 0;
    }
    int hc = Height(bt->firstChild);
    int hs = Height(bt->nextSibling);
    if (hc + 1 > hs) return hc + 1;
    else return hs;
}