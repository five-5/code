#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

const int MAXN = 10001;
struct Car {
    char id[8];
    int time;
    char status[4];
}cars[MAXN], valid[MAXN];

bool cmp(const Car &a, const Car &b) {
    if (strcmp(a.id, b.id)) return strcmp(a.id, b.id) < 0;
    else return a.time < b.time;
}

bool cmpt(const Car &a, const Car &b) {
    return a.time < b.time;
}

int allTime(int hh, int mm, int ss) {
    return hh * 3600 + mm * 60 + ss;
}

int validCount = 0;
std::map<std::string, int> parkTime;
int main()
{
    int n, k, hh, mm, ss;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s %d:%d:%d %s", cars[i].id, &hh, &mm, &ss, cars[i].status);
        cars[i].time = allTime(hh, mm, ss);
    }
    std::sort(cars, cars + n, cmp);
    int maxTime = -1;  // 记录最长时间
    for (int i = 0; i < n - 1; ++i) {
        if (!strcmp(cars[i].id, cars[i+1].id) &&
            !strcmp(cars[i].status, "in") &&
            !strcmp(cars[i+1].status, "out")) {
                valid[validCount++] = cars[i];
                valid[validCount++] = cars[i + 1];
                if (parkTime.count(cars[i].id) == 0) {
                    parkTime[cars[i].id] = 0;
                }
                parkTime[cars[i].id] = parkTime[cars[i].id] + (cars[i+1].time - cars[i].time);
                maxTime = std::max(maxTime, parkTime[cars[i].id]);
            }
    }
    std::sort(valid, valid + validCount, cmpt);
    int now = 0, carNum = 0;
    for (int i = 0; i < k; ++i) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int query = allTime(hh, mm, ss);
        while (now < validCount && valid[now].time <= query) {
            if (!strcmp(valid[now].status, "in")) ++carNum;
            else --carNum;
            ++now;
        }
        printf("%d\n", carNum);
    }

    for (auto it = parkTime.begin(); it != parkTime.end(); ++it) {
        if (it->second == maxTime) printf("%s ", it->first.c_str());
    }


    printf("%02d:%02d:%02d", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
    return 0;
}
