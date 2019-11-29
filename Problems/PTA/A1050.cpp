#include <iostream>
#include <string>

int hashTable[256] = {0};

int main()
{
    std::string s1, s2;
    getline(std::cin, s1);
    getline(std::cin, s2);
    for (int i = 0; i < s2.size(); ++i) {
        ++hashTable[s2[i]];
    }

    for (int i = 0; i < s1.size(); ++i) {
        if (hashTable[s1[i]] == 0) {
            printf("%c", s1[i]);
        }
    }
    return 0;
}
