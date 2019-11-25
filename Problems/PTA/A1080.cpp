#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 40001

int n, m, k;
int quota[101];
struct cur_quota {
    int count = 0;   // 记录已录取学生人数
    int index = 0;   // 记录最后一个录取学生的下标，便于比较是否存在同排名
}cur[101];

struct applicant {
    int num;
    int gradee;
    int gradei;
    int total;
    int school[5];
    int rank;
    int admmit;
}apps[maxn];

bool cmp(const applicant &a, const applicant &b) {
    if (a.total != b.total) return a.total > b.total;
    else return a.gradee > b.gradee;
}

bool cmps(const applicant &a, const applicant &b) {
    if (a.admmit != b.admmit) return a.admmit < b.admmit;
    else return a.num < b.num;
}

void init()
{
    for (int i = 0; i < n; ++i) {
        apps[i].num = i;
        apps[i].total = 0;
        memset(apps[i].school, -1, sizeof(apps[i].school));
        apps[i].rank = -1;
        apps[i].admmit = 100; // 因为学校最大为100，在后面学校排序时没有录取的排在后面
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &quota[i]);
    }
    init();
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &apps[i].gradee, &apps[i].gradei);
        apps[i].total = apps[i].gradee + apps[i].gradei;
        for (int j = 0; j < k; ++j) {
            scanf("%d", &apps[i].school[j]);
        }
    }

    std::sort(apps, apps + n, cmp); // 按总成绩和gradee排序
    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && (apps[i].total != apps[i-1].total || apps[i].gradee != apps[i-1].gradee)) {
            r = i;
        }
        apps[i].rank = r;
        for (int j = 0; j < k; ++j) {
            int num = apps[i].school[j];
            // 人数已达上限并且不存在与已录取学生同排名的情况下，进行下一个选项判断
            if (cur[num].count >= quota[num] && apps[(cur[num].index)].rank < apps[i].rank) {
                continue;
            } else {
                apps[i].admmit = num;
                ++cur[num].count;
                cur[num].index = i;
                break;
            }
        }
    }
    std::sort(apps, apps + n, cmps);  // 按学校和学生编号排序
    int start = 0;
    for (int i = 0; i < m; ++i) {
        if (cur[i].count == 0) {
            printf("\n");
        } else {
            printf("%d", apps[start].num);
            for (int j = 1; j < cur[i].count; ++j) {
                printf(" %d", apps[start + j].num);
            }
            start += cur[i].count;  // 存储下一个学校输出的学生首编号
            printf("\n");
        }
    }
    return 0;
}
