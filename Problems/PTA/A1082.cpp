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

    // ��left��right��λ��ͬһС��
    while (left + 4 <= right) {
        right -= 4;
    }

    // ����ÿ��С��
    for (; left < lenth; right += 4) {
        bool flag = false;    // �Ƿ��л��۵�0
        bool isPrint = false; // �Ƿ�����ýڵ�������
        for (; left <= right; ++left) {
            if (left > 0 && num[left] == '0') {
                flag = true;
            } else {
                if (flag == true) {
                    std::cout << " " << number[0];
                    flag = false;
                }

                // ������λ����Ҫ����ո�
                if (left > 0) std::cout << " ";
                std::cout << number[num[left] - '0'];
                isPrint = true;
                if (left != right) {
                    std::cout << " " << units[right - left - 1];
                }
            }
        }
        // ���Ǹ�λ��Ҫ��������
        if (isPrint && right != lenth - 1) {
            std::cout << " " << units[(lenth - 1 - right) / 4 + 2];
        }
    }

    return 0;
}
