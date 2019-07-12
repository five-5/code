/*
 * @Author: five-5
 * @Date: 2019-07-12 16:25:08
 * @Description: 
 * @LastEditTime: 2019-07-12 17:16:24
 */

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

#include "HashTable.hpp"

// 读文件内容到vector中
void readFile(std::string filename, std::vector<std::string> &words) {
    std::ifstream input(filename);
    if (!input.is_open()) {
        printf("fail to open %s\n", filename.c_str());
    }
    std::string line, word;

    while (std::getline(input, line)) {
        std::istringstream istream(line);
        while (istream >> word)
        {
            words.push_back(word);
        }
    }
}

int main()
{
    std::vector<std::string> words;
    readFile("Pride And prejudice.txt", words);
    clock_t start, end;
    start = clock();
    HashTable<std::string, int> ht = HashTable<std::string, int>();
    for (const auto & word: words) {
        if (ht.contains(word)) {
            ht.set(word, ht.get(word) + 1);
        } else {
            ht.add(word, 1);
        }
    }

    for (const auto & word: words) {
        ht.contains(word);
    }

    end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;

    printf("HashTable: %f s\n", duration);
    return 0;
}