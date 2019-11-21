#include <iostream>
#include <string>

char units[][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
char number[][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{
    std::string num;
    std::cin >> num;

    int lenth = num.size();
    int left = 0, right = lenth - 1;

    if (num[0] == '-') {
        std::cout << "Fu";
        ++left;
    }

    // 将left与right定位到同一小节
    while (left + 4 <= right) {
        right -= 4;
    }

    // 遍历每个小节
    for (; left < lenth; right += 4) {
        bool flag = false;    // 是否含有积累的0
        bool isPrint = false; // 是否输出该节的任意数
        for (; left <= right; ++left) {
            if (left > 0 && num[left] == '0') {
                flag = true;
            } else {
                if (flag == true) {
                    std::cout << " " << number[0];
                    flag = false;
                }

                // 不是首位，需要输出空格
                if (left > 0) std::cout << " ";
                std::cout << number[num[left] - '0'];
                isPrint = true;
                if (left != right) {
                    std::cout << " " << units[right - left - 1];
                }
            }
        }
        // 不是个位就要输出万或亿
        if (isPrint && right != lenth - 1) {
            std::cout << " " << units[(lenth - 1 - right) / 4 + 2];
        }
    }

    return 0;
}
