#include <iostream>

struct info {
    char name[11];
    char number[11];
    int grade;
}tmp, g_max, g_min;

int main()
{
    int n;
    std::cin >> n;
    g_max.grade = -1;
    g_min.grade = 101;
    for(int i = 0; i < n; ++i) {
        std::cin >> tmp.name >> tmp.number >> tmp.grade;
        if (tmp.grade > g_max.grade) {
            g_max = tmp;
        }

        if (tmp.grade < g_min.grade) {
            g_min = tmp;
        }
    }

    printf("%s %s\n", g_max.name, g_max.number);
    printf("%s %s\n", g_min.name, g_min.number);

    return 0;
}
