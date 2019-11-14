#include <iostream>
#include <string>

struct info {
    std::string name;
    std::string ID;
    int grade;
} maxFe, minMa;

int main()
{
    maxFe.grade = -1;
    minMa.grade = 101;
    int N;
    std::cin >> N;
    while (N--) {
        std::string tm_name, tm_ID;
        char gender;
        int grade;
        std::cin >> tm_name >> gender >> tm_ID >> grade;
        if (gender == 'F' && grade > maxFe.grade ) {
            maxFe.name = tm_name;
            maxFe.ID = tm_ID;
            maxFe.grade = grade;
        }
        if (gender == 'M' && grade < minMa.grade) {
            minMa.name = tm_name;
            minMa.ID = tm_ID;
            minMa.grade = grade;
        }
    }

    if (maxFe.grade != -1) {
        std::cout << maxFe.name << " " << maxFe.ID << std::endl;
    } else {
        std::cout << "Absent" << std::endl;
    }

    if (minMa.grade != 101) {
        std::cout << minMa.name << " " << minMa.ID << std::endl;
    } else {
        std::cout << "Absent" << std::endl;
    }

    if (maxFe.grade != -1 && minMa.grade != 101) {
        std::cout << maxFe.grade - minMa.grade << std::endl;
    } else {
        std::cout << "NA" << std::endl;
    }

    return 0;
}
/*
CASE 1
3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95

Mary EE990830
Joe Math990112
6

CASE2
1
Jean M AA980920 60

Absent
Jean AA980920
NA
*/
