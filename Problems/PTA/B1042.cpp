#include <iostream>
#include <string>
#include <cctype>

char ch[26] = {0};

int main()
{
    std::string str;
    getline(std::cin, str);
    int maxindex = 0;
    int lenth = str.size();
    for (int i = 0; i < lenth; ++i) {
        if (isalpha(str[i])) {
            str[i] = tolower(str[i]);
            int index = str[i] - 'a';
            ++ch[index];
            if (ch[maxindex] == ch[index]) {
                if (index < maxindex) maxindex = index;
            } else if (ch[maxindex] < ch[index]) {
                maxindex = index;
            }
        }
    }
    printf("%c %d", maxindex+'a', ch[maxindex]);
}
