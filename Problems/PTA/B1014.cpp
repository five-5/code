#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>

char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    char sentence[4][61];
    int lenth[4];
    for (int i = 0; i < 4; ++i) {
        std::cin.getline(sentence[i], 61);
        lenth[i] = strlen(sentence[i]);
    }

    // 获取星期
    int i;
    for (i = 0; i < lenth[0] && i < lenth[1]; ++i) {
        if ((sentence[0][i] == sentence[1][i]) && (sentence[0][i] >= 'A' && sentence[0][i] <= 'G')) {
            printf("%s ", day[sentence[0][i] - 'A']);
            break;
        }
    }

    // 获取钟头数
    for (i = i + 1; i < lenth[0] && i < lenth[1]; ++i) {
        if ((sentence[0][i] == sentence[1][i])) {
            if (isdigit(sentence[0][i])) {
                printf("%02d:", sentence[0][i] - '0');
            } else if (sentence[0][i] >= 'A' && sentence[0][i] <= 'N') {
                printf("%02d:", sentence[0][i] - 'A' + 10);
            } else {
                continue;
            }
            break;
        }
    }

    // 获取分钟数
    for (i = 0; i < lenth[2] && i < lenth[3]; ++i) {
        if ((sentence[2][i] == sentence[3][i]) && isalpha(sentence[2][i])) {
            printf("%02d", i);
            break;
        }
    }

    return 0;
}
