#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
bool hashTable[256];
std::string str;
int main()
{
    memset(hashTable, true, sizeof(hashTable));
    getline(std::cin, str);
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
        hashTable[str[i]] = false;
    }
    getline(std::cin, str);
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            char tmp = str[i] - 'A' + 'a';
            if (hashTable[tmp] == true && hashTable['+'] == true ) {
                printf("%c", str[i]);
            }
        } else if (hashTable[str[i]] == true){
                printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}
