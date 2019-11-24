#include <iostream>
#include <string>
#include <algorithm>

#define maxn 100001

struct student {
    std::string ID;
    std::string name;
    int grade;

    void print() {
        std::cout << ID << " " << name << " " << grade << std::endl;
    }
}stu[maxn];

bool cmp1(student a, student b) {
    return a.ID < b.ID;
}

bool cmp2(student a, student b) {
    if (a.name != b.name) return a.name <= b.name;
    else return a.ID < b.ID;
}

bool cmp3(student a, student b) {
    if (a.grade != b.grade) return a.grade <= b.grade;
    else return a.ID < b.ID;
}


int main()
{
    int N, C;
    std::cin >> N >> C;
    for (int i = 0; i < N; ++i) {
        std::cin >> stu[i].ID >> stu[i].name >> stu[i].grade;
    }
    // ¸ù¾ÝCÅÅÐò
    switch (C) {
    case 1:
        std::sort(stu, stu + N, cmp1);
        break;
    case 2:
        std::sort(stu, stu + N, cmp2);
        break;
    case 3:
        std::sort(stu, stu + N, cmp3);
    }

    for (int i = 0; i < N; ++i) {
        stu[i].print();
    }

    return 0;
}
