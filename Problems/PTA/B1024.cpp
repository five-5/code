#include <iostream>
#include <cstdio>
#include <string>

int str2num(const std::string &str) {
    int ret = 0;
    for (int i = 0; i < str.size(); ++i) {
        ret = ret * 10 + str[i] - '0';
    }

    return ret;
}

int main()
{
    std::string input, output = "";
    std::cin >> input;

    char pos;
    if (input[0] == '-') {
        printf("%c", '-');
    }
    int index = 0;
    int lenth = input.size();
    for (int i = 1; i < lenth; ++i) {
        if (input[i] == 'E') {
            index = i;
            pos = input[index + 1];
            break;
        }
    }

    std::string num = input.substr(1, index - 1);
    int nlenth = num.size();
    int exp = str2num(input.substr(index+2, lenth - index - 2));
    size_t point = num.find(".", 0);

    // 正数处理
    if (pos == '+') {
        int bit = exp - nlenth + 1 + point;
        if (bit < 0) {
            for (int i = 0; i < nlenth; ++i) {
                    if (i != point ) {
                        printf("%c", num[i]);
                    }
                    if (i == point + exp) {
                        printf(".");
                    }

            }
        } else {
            for (int i = 0; i < nlenth; ++i) {
                    if (i != point ) {
                        printf("%c", num[i]);
                    }
            }
            for (int i = 0; i < bit; ++i) {
                printf("0");
            }
        }
    } else {
        for (int i = 0; i < exp; ++i) {
            printf("0");
            if (i == 0) {
                printf(".");
            }
        }
        for (int i = 0; i < nlenth; ++i) {
                    if (i != point ) {
                        printf("%c", num[i]);
                    }
        }
    }
    return 0;
}
