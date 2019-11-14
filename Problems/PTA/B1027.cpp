#include <iostream>
#include <cmath>

void print(char c, int n) {
    bool flag = false;
    int x = n;
    int i = 0;
    while (!(flag && x == n + 2)) {
        for (int j = 0; j < i; ++j) {
            std::cout << " ";
        }
        for (int j = 0; j < x; ++j) {
            std::cout << c;
        }

        if (x == 1) {
            flag = true;
        }

        if (!flag) {
            ++i;
            x -= 2;
        } else {
            --i;
            x += 2;
        }
        std::cout << std::endl;
    }

}

int calcX(int n) {
    return sqrt((n+1)/2);
}

int main()
{
    int n;
    char c;
    std::cin >> n >> c;
    int x = calcX(n);
    print(c, 2 * x - 1);
    std::cout << n - 2 * x *x  + 1 << std::endl;

    return 0;
}
