/*
 * @Author: five-5
 * @Date: 2019-07-04 23:27:45
 * @Description: test for Trie DS
 * @LastEditTime: 2019-07-04 23:55:10
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include <string>

#include "Trie.hpp"

int main()
{
    std::vector<std::string> words;
    std::ifstream input_file("Pride And prejudice.txt");
    // std::ifstream input_file("test.txt");
    std::string line, word;

    if (!input_file.is_open()) {
        std::cout << "File does not exist" << std::endl;
        return -1;
    }

    while (std::getline(input_file, line))
    {
        std::istringstream istream(line);
        while (istream >> word)
        {
            words.push_back(word);
            // printf("%s\n", word.c_str());
        }
    }

    std::cout << "read file finished." << std::endl;
    clock_t start, end;
    
    start = clock();
    Trie trie;

    for (auto w : words) {
        trie.add(w);
    }

    for (auto w : words) {
        if (!trie.contains(w)) {
            printf("error\n");
            break;
        }
    }

    end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total different words: %d\n", trie.size());
    printf("Trie: %lf s\n", duration);

    return 0;
}