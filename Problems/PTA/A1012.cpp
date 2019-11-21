#include <iostream>
#include <algorithm>
#include <cmath>

struct perf{
    int ID;
    int grade[4];
}stu[2001];

char course[4] = {'A', 'C', 'M', 'E'};
int Rank[1000000][4] = {0};  // һά�±��ʾID�ţ���ά��Ӧ�ṹ���и��ɼ�����

int now; // �����ɼ��±�

bool cmp (perf a, perf b) {
    return a.grade[now] > b.grade[now];
}
int main()
{
    int n, m;
    std::cin >> n >> m;
    // grade 0-3 ��Ӧcourse
    for (int i = 0; i < n; ++i) {
        std::cin >> stu[i].ID >> stu[i].grade[1] >> stu[i].grade[2] >> stu[i].grade[3];
        stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0) + 0.5;
    }

    for (now = 0; now < 4; ++now) {
        std::sort(stu, stu + n, cmp);
        Rank[stu[0].ID][now] = 1;
        for (int i = 1; i < n; ++i) {
            if (stu[i].grade[now] == stu[i-1].grade[now]) { // ��ǰһ����ͬ����
                Rank[stu[i].ID][now] = Rank[stu[i-1].ID][now];
            } else {
                Rank[stu[i].ID][now] = i + 1;
            }
        }
    }

    int query;
    for (int i = 0; i < m; ++i) {
        std::cin >> query;
        if (Rank[query][0] == 0) {
            std::cout << "N/A" << std::endl;
        } else {
            int k = 0;   // ѡ���ĸ��ɼ�����С����
            for (int j = 1; j < 4; ++j) {
                if (Rank[query][k] > Rank[query][j]) {
                    k = j;
                }
            }
            std::cout << Rank[query][k] << " " << course[k] << std::endl;
        }
    }
    return 0;
}
