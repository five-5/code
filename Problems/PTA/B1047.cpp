#include <cstdio>
#include <algorithm>

int group[1001] = {0};

int main()
{
    int n, gp, member, score, maxscore = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d-%d %d", &gp, &member, &score);
        group[gp] += score;
        if (group[maxscore] < group[gp]) {
            maxscore = gp;
        }
    }
    printf("%d %d", maxscore, group[maxscore]);
    return 0;
}
