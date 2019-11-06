#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int steps = 0;
    while (n!=1) {
        ++steps;
        if (n & 0x01) { // ÆæÊý
            n = ((3*n) + 1 ) / 2;
        } else {
            n = n / 2;
        }
    }

    std::cout << steps << std::endl;
    return 0;
}
