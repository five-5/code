#include <iostream>

long long nums(long long num, long long dnum) {
    long long dn = 0;
    while(num != 0) {
        if (num % 10 == dnum) {
            dn = dn * 10 + dnum;
        }
        num = num / 10;
    }

    return dn;
}

int main()
{
    long long A, DA, B, DB, PA, PB;

    std::cin >> A >> DA >> B >> DB;

    PA = nums(A, DA);
    PB = nums(B, DB);
    std::cout << PA + PB << std::endl;

    return 0;
}

