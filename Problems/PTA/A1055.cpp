#include <iostream>
#include <string>
#include <algorithm>

#define maxn 100001
struct billionaire {
    std::string name;
    int age;
    int net_worth;

    void print() {
        std::cout << name << " " << age << " " << net_worth << std::endl;
    }
}bire[maxn];

bool cmp (billionaire a, billionaire b) {
    if (a.net_worth != b.net_worth) return a.net_worth > b.net_worth;
    else if (a.age != b.age) return a.age < b.age;
    else if (a.name != b.name) return a.name < b.name;
}

bool isValid(int age, int amin, int amax) {
    if (age >= amin && age <= amax) return true;
    else return false;
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        std::cin >> bire[i].name >> bire[i].age >> bire[i].net_worth;
    }
    std::sort(bire, bire + N, cmp);
    for (int i = 1; i <= M; ++i) {
        int num, amin, amax;
        std::cin >> num >> amin >> amax;
        std::cout << "Case #" << i << ":" << std::endl;
        int count = 0;

        for (int j = 0; j < N; ++j) {
            if (count >= num) break;
            if (isValid(bire[j].age, amin, amax)) {
                bire[j].print();
                ++count;
            }
        }
        if (count == 0) std::cout << "None" << std::endl;
    }
    return 0;
}
