#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#define maxn 1001

struct record {
    std::string name;
    int month;
    int day;
    int hour;
    int minute;
    std::string word;
    void print() {
        std::cout << name << " " << month << ":" << day << ":" << hour << ":" << minute << " " << word << std::endl;
    }
} records[maxn], tmp;

bool cmp(const record &a, const record &b) {
    if (a.name != b.name) return a.name < b.name;
    else if (a.month != b.month) return a.month < b.month;
    else if (a.day != b.day) return a.day < b.day;
    else if (a.hour != b.hour) return a.hour < b.hour;
    else if (a.minute != b.minute) return a.minute < b.minute;
}

int toll[24] = {0};

void get_ans(int on, int off, int &time, int &money) {
    tmp = records[on];
    while (tmp.day < records[off].day || tmp.hour < records[off].hour || tmp.minute < records[off].minute) {
        ++time;
        money += toll[tmp.hour];
        ++tmp.minute;
        if (tmp.minute == 60) {
            tmp.minute = 0;
            tmp.hour++;
        }
        if (tmp.hour == 24) {
            tmp.hour = 0;
            tmp.day++;
        }
    }
}

int main()
{
    for (int i = 0; i < 24; ++i) {
        scanf("%d", &toll[i]);
    }

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        std::cin >> records[i].name;
        scanf("%d:%d:%d:%d", &records[i].month, &records[i].day, &records[i].hour, &records[i].minute);
        std::cin >> records[i].word;
    }
    std::sort(records, records + n, cmp);
    // 筛选有效的
    int on = 0, off, next; // on和off是配对的一条，next为下一个用户
    while (on < n) {
        int needPrint = 0; // 记录是否找到有效记录 2为找到
        next = on;         // 从on开始扫描
        while (next < n && records[next].name == records[on].name) {
            if (needPrint == 0 && records[next].word == "on-line") {
                needPrint = 1;
            } else if (needPrint == 1 && records[next].word == "off-line") {
                needPrint = 2;
            }
            ++next;
        }

        if (needPrint < 2) {
            on = next;
            continue;
        }

        int allMoney = 0;
        printf("%s %02d\n", records[on].name.c_str(), records[on].month);
        while (on < next) {
            while (on < next -1 && !(records[on].word == "on-line" && records[on + 1].word == "off-line")) {
                ++on;
            }
            off = on + 1;
            if (off == next) {
                on = next;
                break;
            }
            printf("%02d:%02d:%02d ", records[on].day, records[on].hour, records[on].minute);
            printf("%02d:%02d:%02d ", records[off].day, records[off].hour, records[off].minute);
            int time = 0, money = 0;
            get_ans(on, off, time, money);
            allMoney += money;
            printf("%d $%.2f\n", time, money / 100.0); // cents -> dollar
            on = off + 1;
        }
        printf("Total amount: $%.2f\n", allMoney / 100.0);
    }
    return 0;
}
