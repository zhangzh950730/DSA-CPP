//
// Created by 张之豪 on 2021/12/1.
//

#include "../BiTNode.h"

typedef struct CSNode {
    ElemType data;
    struct CSNode *firstChild, *nextSibling;
} CSNode, *CSTree;