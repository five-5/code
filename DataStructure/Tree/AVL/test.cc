/*
 * @Author: five-5
 * @Date: 2019-07-10 20:48:59
 * @Description: test AVL
 * @LastEditTime: 2019-07-10 22:07:46
 */

#include <fstream>
#include <iostream>
#include <stdexcept>
#include "AVL.hpp"


int main()
{
    std::vector<std::string> words;
    std::string filename = "Pride And prejudice.txt";
    std::ifstream txt_file(filename);
    if (!txt_file.is_open()) {
        printf("fail to open %s\n", filename.c_str());
        return -1;
    }

    AVL<std::string, int> map;
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
                map.Add(w, 1);
            }
    }

    printf("Total different words: %d\n", map.size());
    printf("Frequency of PRIDE: %d\n", map.get("pride"));
    printf("Frequency of PREJUDICE: %d\n", map.get("prejudice"));
    printf("isBST: %d\n", map.isBST());
    printf("isBalanced: %d\n", map.isBalanced());


    for (auto &w : words) {
        map.Remove(w);
        if (!map.isBST() && !map.isBalanced()) {
            throw std::runtime_error("AVL BST and Balance error\n");
        } else if (!map.isBST()) {
            throw std::runtime_error("AVL BST error\n");
        } else if (!map.isBalanced()) {
            throw std::runtime_error("AVL Balance error\n");
        }
    }
}