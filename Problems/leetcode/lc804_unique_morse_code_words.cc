/*
 * @Author: five-5
 * @Description: leetcode 804. Unique Morse Code Words
 * @Date: 2019-04-02
 * @LastEditTime: 2019-04-02
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>

std::vector<std::string> table={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Solution {
public:
    int uniqueMorseRepresentations(std::vector<std::string>& words) {
        if (words.empty()) {
            return 0;
        }

        std::set<std::string> unique_morse;
        for (auto w : words) {
            std::string temp;
            for (auto ch : w) {
                temp += table[ch - 'a'];
            }
            unique_morse.insert(temp);
        }
        return unique_morse.size();
    }
};

int main()
{
    Solution so;
    std::vector<std::string> words = {"gin", "zen", "gig", "msg"};
    std::cout << so.uniqueMorseRepresentations(words);
}