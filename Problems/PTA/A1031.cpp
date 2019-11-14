#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;

    int n = s.size();
    int n1 , n3;
    n1 = n3 = (n+2) / 3;
    int n2 = n - n1 - n3 + 2;

    int space_num = n2 - 2;
    for (int i = 0; i < n1 - 1; ++i) {
        std::cout << s[i];
        for (int j = 0; j < space_num; ++j) {
            std::cout << " ";
        }
        std::cout << s[n-1-i] << std::endl;
    }
    for (int i = 0; i < n2; ++i) {
        std::cout << s[n1 - 1 +i];
    }

    return 0;
}
