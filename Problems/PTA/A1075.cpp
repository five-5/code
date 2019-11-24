#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

#define maxn 10001
struct pat {
    int ID;
    int partial_score[5];
    int total;
    int perfect;
    bool isPrint;
} pats[maxn];
int N, K, M;
int full_mark[5];

bool cmp(pat a, pat b) {
    if (a.total != b.total) return a.total > b.total;
    else if (a.perfect != b.perfect) return a.perfect > b.perfect;
    else return a.ID < b.ID;
}

void init() {
    for (int i = 1; i <= N; ++i) {
        pats[i].ID = i;
        pats[i].total = 0;
        pats[i].perfect = 0;
        pats[i].isPrint = false;
        memset(pats[i].partial_score, -1, sizeof(pats[i].partial_score));
    }
}

int main()
{
    std::cin >> N >> K >> M;
    init();
    for (int i = 0; i < K; ++i) std::cin >> full_mark[i];

    for (int i = 0; i < M; ++i) {
        int tmp, id, score;
        std::cin >> id >> tmp;
        pats[id].ID = id;
        std::cin >> score;
        if (score != -1)  {
            pats[id].isPrint = true;
        }
        // 改为0，便于后续输出
        if (score == -1 && pats[id].partial_score[tmp - 1] == -1) pats[id].partial_score[tmp - 1] = 0;
        if (score > pats[id].partial_score[tmp - 1]) {
            pats[id].partial_score[tmp - 1] = score;
            if (score == full_mark[tmp - 1]) ++pats[id].perfect;
        }

    }


    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < K; ++j) {
            if (pats[i].partial_score[j] != -1)
                pats[i].total += pats[i].partial_score[j];
        }
    }

    std::sort(pats + 1, pats + N + 1, cmp);
    int r = 1;
    for (int i = 1; i <= N && pats[i].isPrint; ++i) {
        if (i > 0 && pats[i].total != pats[i - 1].total) {
            r = i;
        }
        printf("%d %05d %d", r, pats[i].ID, pats[i].total);
        for (int j = 0; j < K; ++j) {
            if (pats[i].partial_score[j] == -1) printf(" -");
            else printf(" %d", pats[i].partial_score[j]);
        }
        printf("\n");
    }
    return 0;
}
