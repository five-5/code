#include <iostream>

int up(int n) {
    double result = n * 0.5;
    int ret = n / 2;
    if (result > ret) {
        return ret + 1;
    } else {
        return ret;
    }
}

int main()
{
    int n;
    char c;
    std::cin >> n >> c;

    int rows = up(n);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i != 0 && i != rows - 1) && (j != 0 && j != n-1)) {
                std::cout << " ";
            } else {
                std::cout << c;
            }
        }
        if (i != rows - 1) {
            std::cout << std::endl;
        }
    }

    return 0;
}
