#include <iostream>
#include <string>

char radix[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};

int main()
{
    std::string A, B, ans;
    std::cin >> A >> B;

    int alenth = A.size();
    int blenth = B.size();
    int lenth = alenth > blenth ? alenth : blenth;
    for (int i = 0; i < lenth; ++i) {
        int tempA = i < alenth ? A[alenth - 1 - i] - '0': 0;
        int tempB = i < blenth ? B[blenth - 1 - i] - '0': 0;
        if (i % 2 == 0) {
            ans.insert(0, 1, radix[(tempA + tempB)% 13]);
        } else {
            if (tempB >= tempA) {
                tempB -= tempA;
            } else {
                tempB = tempB + 10 - tempA;
            }
            ans.insert(0, 1, tempB + '0');
        }
    }
    std::cout << ans;
    return 0;
}
