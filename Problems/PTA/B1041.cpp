#include <iostream>
#include <string>
#include <map>

struct info {
    std::string number;
    int sit;
}student;

std::map<int, info> tables;

int main()
{
    int N;
    std::cin >> N;
    while(N--) {
        int pre_sit;
        std::cin >> student.number >> pre_sit;
        std::cin >> student.sit;
        tables[pre_sit] = student;
    }
    int M;
    std::cin >> M;
    while(M--) {
        int query;
        std::cin >> query;
        std::cout << tables[query].number << " " << tables[query].sit << std::endl;
    }
    return 0;
}
