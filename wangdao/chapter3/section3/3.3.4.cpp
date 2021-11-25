//
// Created by 张之豪 on 2021/11/25.
//

#include "../SqQueue.h"

SqQueue q;
SqQueue q1;
SqQueue q2;

void manager() {
    int i = 0, j = 0;
    ElemType x;
    while (j < 10) {
        if (IsEmpty(q1) && i < 4) {
            DeQueue(q1, x);
            EnQueue(q, x);
            i++, j++;
        } else if (i == 4 && !IsEmpty(q2)) {
            DeQueue(q2, x);
            EnQueue(q, x);
            j++, i = 0;
        } else {
            while (j < 10 && i < 4 && !IsEmpty(q2)) {
                DeQueue(q2, x);
                EnQueue(q, x);
                i++, j++;
            }
            i = 0;
        }
        if (IsEmpty(q1) && IsEmpty(q2)) j = 11;
    }
}
