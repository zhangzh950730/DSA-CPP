//
// Created by 张之豪 on 2021/11/24.
//
#include "../../LinkedList.h"

LinkedList solution(LinkedList L1, LinkedList L2) {
    int len1 = length(L1);
    int len2 = length(L2);
    int distance;
    LinkedList longList, shortList;
    if (len1 > len2) {
        longList = L1->next;
        shortList = L2->next;
        distance = len1 - len2;
    } else {
        longList = L2->next;
        shortList = L1->next;
        distance = len2 - len1;
    }
    while (distance--) {
        longList = longList->next;
    }
    while (longList != NULL) {
        if (longList == shortList) {
            return longList;
        } else {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return NULL;
}