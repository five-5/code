#include <iostream>
#include <algorithm>

#define maxn 100001

enum Rank{
    NONE,
    SMALLMAN,
    FOOLMAN,
    NOBLEMAN,
    SAGE
};

struct info {
    int ID;
    int virGrade;
    int talGrade;
    int total = 0;
    Rank type = NONE;
    void print() {
        std::cout << ID << " " << virGrade << " " << talGrade << std::endl;
    }
} person[maxn];

bool cmp(info a, info b) {
    if (a.type != b.type) return a.type > b.type;
    else if (a.total != b.total) return a.total > b.total;
    else if (a.virGrade != b. virGrade) return a.virGrade > b.virGrade;
    else return a.ID < b.ID;
}

int main()
{
    int N, L, H;
    int count = 0;
    std::cin >> N >> L >> H;
    for (int i = 0; i < N; ++i) {
        std::cin >> person[i].ID >> person[i].virGrade >> person[i].talGrade;
        // 判断德才分情况
        if (person[i].virGrade < L || person[i].talGrade < L) continue;
        else if (person[i].virGrade >= H &&  person[i].talGrade >= H) person[i].type = SAGE;
        else if (person[i].virGrade >= H && person[i].talGrade < H) person[i].type = NOBLEMAN;
        else if (person[i].talGrade < H && person[i].virGrade < H && person[i].virGrade >= person[i].talGrade) person[i].type = FOOLMAN;
        else person[i].type = SMALLMAN;

        ++count;
        person[i].total = person[i].virGrade + person[i].talGrade;

    }
    // sort
    std::sort(person, person + N, cmp);

    std::cout << count << std::endl;
    for (int i = 0; i < count; ++i) {
        person[i].print();
    }

    return 0;
}
