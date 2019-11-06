#include <iostream>
#include <string>
#include <map>

std::map<char,std::string> table{{'0',"ling"},
                                {'1',"yi"},
                                {'2',"er"},
                                {'3',"san"},
                                {'4',"si"},
                                {'5',"wu"},
                                {'6',"liu"},
                                {'7',"qi"},
                                {'8',"ba"},
                                {'9',"jiu"}};
int main()
{
    std::string n;
    std::cin >> n;

    int num = 0;
    for(auto ch : n) {
        num += ch - '0';
    }

    std::string tmp = std::to_string(num);

    std::cout << table[tmp[0]];
    for(int i = 1; i < tmp.size(); ++i) {
        std::cout << " " << table[tmp[i]];
    }

    return 0;
}
