// Phone Bills
// Created by zhang on 2020/8/17.
//

#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAX_N = 1010;
int toll[25]; //资费

struct Record {
    char name[25];
    int month, dd, hh, mm;
    bool status; //true表示on-line,否在为off-line
} rec[MAX_N], temp;

bool cmp(Record a, Record b) {
    int s = strcmp(a.name, b.name);
    if (s != 0) return s < 0;
    else if (a.month != b.month) return a.month < b.month;
    else if (a.dd != b.dd) return a.dd < b.dd;
    else if (a.hh != b.hh) return a.hh < b.hh;
    else return a.mm < b.mm;
}

void get_ans(int on, int off, int &time, int &money) {
    temp = rec[on];
    while (temp.dd < rec[off].dd || temp.hh < rec[off].hh || temp.mm < rec[off].mm) {
        time++;
        money += toll[temp.hh];
        temp.mm++;
        if (temp.mm >= 60) {
            temp.mm = 0;
            temp.hh++;
        }
        if (temp.hh >= 24) {
            temp.hh = 0;
            temp.dd++;
        }
    }
}

int main() {
    for (int i = 0; i < 24; ++i) { //资费
        scanf("%d", &toll[i]);
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char line[10];
        scanf("%s %d:%d:%d:%d %s", &rec[i].name, &rec[i].month, &rec[i].dd, &rec[i].hh, &rec[i].mm, line);
        rec[i].status = strcmp(line, "on-line") == 0;
    }
    sort(rec, rec + n, cmp);
    int on = 0, off, next; // on和off为配对的两条记录,next记录为下一个用户
    while (on < n) { //循环处理每个用户的所有记录
        int needPrint = 0;
        next = on;
        while (next < n && strcmp(rec[next].name, rec[on].name) == 0) {
            if (needPrint == 0 && rec[next].status) { //找到on
                needPrint = 1;
            } else if (needPrint == 1 && !rec[next].status) { //找到off
                needPrint = 2;
            }
            next++; //自增,直到找到不同名字,即下一个用户
        }
        if (needPrint < 2) { //没有找到配对的on-off
            on = next;
            continue;
        }
        int allMoney = 0;
        printf("%s %02d\n", rec[on].name, rec[on].month);
        while (on < next) {
            while (on < next - 1 && !(rec[on].status && !rec[on + 1].status)) { //找到连续的on和off
                on++;
            }
            off = on + 1; //off必须是on的下一个
            if (off == next) { //输出完毕当前用户的所有配对
                on = next;
                break;
            }
            printf("%02d:%02d:%02d ", rec[on].dd, rec[on].hh, rec[on].mm);
            printf("%02d:%02d:%02d ", rec[off].dd, rec[off].hh, rec[off].mm);
            int time = 0, money = 0;
            get_ans(on, off, time, money);
            allMoney += money;
            printf("%d $%.2f\n", time, money / 100.0);
            on = off + 1;
        }
        printf("Total amount: $%.2f\n", allMoney / 100.0);
    }
    return 0;
}