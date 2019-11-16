#include <iostream>

char table[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

int main()
{
    int color;
    int result[6] = {0};

    int count = 0;
    for (int i = 0; i < 3; ++i) {
        std::cin >> color;
        if (color < 13) {
            result[count++] = color % 13;
            result[count++] = 0;
            continue;
        }
        do {
            result[count++] = color % 13;
            color /= 13;
        } while (color != 0);
    }
    std::cout << '#';
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j >= 0; --j) {
            std::cout << table[result[i*2+j]];
        }
    }
    return 0;
}

#include <cstdio>

int main()
{
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    printf("#");
    printf("%c%c", table[r / 13], table[r % 13]);
    printf("%c%c", table[g / 13], table[g % 13]);
    printf("%c%c", table[b / 13], table[b % 13]);

    return 0;
}
