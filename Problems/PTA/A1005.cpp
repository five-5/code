#include <iostream>
#include <string>
#include <map>

std::map<char, std::string> digits = {{'0', "zero"},
                                      {'1', "one"},
                                      {'2', "two"},
                                      {'3', "three"},
                                      {'4', "four"},
                                      {'5', "five"},
                                      {'6', "six"},
                                      {'7', "seven"},
                                      {'8', "eight"},
                                      {'9', "nine"}};

int main()
{
    std::string N;
    std::cin >> N;
    int sum = 0;
    for (int i = 0; i < N.size(); ++i) {
        sum += (N[i] - '0');
    }

    std::string ans = std::to_string(sum);
    std::cout << digits[ans[0]];
    for (int i = 1; i < ans.size(); ++i) {
        std::cout << " " << digits[ans[i]];
    }
    return 0;
}
