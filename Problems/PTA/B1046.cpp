#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int a, an, b, bn;
    int acount = 0, bcount = 0;
    while(N--) {
        std::cin >> a >> an >> b >> bn;
        int sum = a + b;
        if (sum == an && sum != bn) {
            ++bcount;
        } else if (sum == bn && sum != an) {
            ++acount;
        }
    }

    std::cout << acount << " " << bcount << std::endl;

    return 0;
}
