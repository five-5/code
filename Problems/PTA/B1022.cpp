#include <iostream>
#include <string>

std::string tr2D(int num, int D)
{
    std::string result = "";
    if (num == 0) {
        result = "0";
    }
    while (num) {
        result.insert(0, 1, '0' + num % D);
        num = num / D;
    }
    return result;
}

int main()
{
    int A, B, D;
    std::cin >> A >> B >> D;

    std::cout << tr2D(A+B,D) << std::endl;
    return 0;
}
