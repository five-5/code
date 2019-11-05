#include <iostream>

double p[1001] = {0.0};
int main()
{
    int k, n;
    double a;

    // first num
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        std::cin >> n >> a;
        p[n] += a;
    }

    // second num
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        std::cin >> n >> a;
        p[n] += a;
    }

    int count = 0;
    for (int i = 0; i < 1001; ++i) {
        if (p[i] != 0)
            ++count;
    }

    std::cout << count;
    for(int i = 1000; i >=0 ; --i) {
        if (p[i] != 0) {
            printf(" %d %.1f", i, p[i]);
        }
    }
}

/*
2 1 2.4 0 3.2
2 2 1.5 1 0.5
*/
