#include <cstdio>
#include <iostream>
#include <algorithm>

#define maxn 200

struct student {
    char name[11];
    char ID[11];
    int grade;
}stu[maxn];

bool cmp(const student &a, const student &b) {
    return a.grade > b.grade;
}

bool isValid(int grade, int grade1, int grade2) {
    if (grade >= grade1 && grade <= grade2) return true;
    else return false;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%s %s %d", stu[i].name, stu[i].ID, &stu[i].grade);
    }
    int grade1, grade2;
    std::cin >> grade1 >> grade2;
    std::sort(stu, stu + n, cmp);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (isValid(stu[i].grade, grade1, grade2)) {
            if (count != 0) std::cout << std::endl;
            printf("%s %s", stu[i].name, stu[i].ID);
            ++count;
        }
    }
    if (count == 0)
        std::cout << "NONE";
    return 0;
}
