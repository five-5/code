/*
 * @Author: five-5
 * @Date: 2019-07-11 23:28:03
 * @Description: 
 * @LastEditTime: 2019-07-12 00:34:29
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "RBTree.hpp"

int main()
{
    std::vector<std::string> words;
    std::string filename = "../AVL/Pride And prejudice.txt";
    std::ifstream txt_file(filename);
    if (!txt_file.is_open()) {
        printf("fail to open %s\n", filename.c_str());
        return -1;
    }

    RBTree<std::string, int> map;
    std::string line, word;
    printf("begin to read data from %s\n", filename.c_str());
    while (std::getline(txt_file, line))
    {
        std::istringstream istream(line);
        while (istream >> word)
        {
            words.push_back(word);
        }
    }
    
    for (auto &w : words) {
        if (map.Contains(w)) {
                map.set(w, map.get(w) + 1);
            } else {
                map.add(w, 1);
            }
    }

    printf("Total different words: %d\n", map.size());
    printf("Frequency of PRIDE: %d\n", map.get("pride"));
    printf("Frequency of PREJUDICE: %d\n", map.get("prejudice"));
    return 0;
}