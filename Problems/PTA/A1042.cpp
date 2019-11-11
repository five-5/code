#include <iostream>
#include <string>
#include <map>

std::map<int, std::string> cards;
int main()
{
    char type[4] = {'S','H','C','D'};
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; j <= 13; ++j) {
            cards[i*13+j] = type[i]+std::to_string(j);
        }
    }
    cards[53] = "J1";
    cards[54] = "J2";

    int n;
    std::cin >> n;
    int num[54];
    for (int i = 0; i < 54; ++i) {
        std::cin >> num[i];
    }

    int start[54] = {0};
    int end[54] = {0};
    for (int i = 1; i <= 54; ++i) {
        start[i-1] = i;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 54; ++j) {
            end[num[j]-1] = start[j];
        }
        for(int k = 0; k < 54; ++k) {
            start[k] = end[k];
        }
    }

    std::cout << cards[start[0]];
    for (int i = 1; i < 54; ++i) {
        std::cout << " " << cards[start[i]];
    }
    std::cout << std::endl;

    return 0;
}
