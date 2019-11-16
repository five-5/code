#include <iostream>

#define Galleon (17*29)
#define Sickle 29

struct currency {
    long long galleon;
    int sickle;
    int knut;
} A, B;

int main()
{
    char c;
    std::cin >> A.galleon >> c >> A.sickle >> c >> A.knut;
    std::cin >> B.galleon >> c >> B.sickle >> c >> B.knut;
    long long tmpA = A.galleon * Galleon + A.sickle * Sickle + A.knut;
    long long tmpB = B.galleon * Galleon + B.sickle * Sickle + B.knut;
    long long result = tmpA + tmpB;
    std::cout << result / Galleon << c << (result % Galleon) / Sickle << c << result % Sickle;
    return 0;
}
