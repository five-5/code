/*
 * @Author: five-5
 * @Description: test for map
 * @Date: 2019-04-02
 * @LastEditTime: 2019-07-10 22:38:14
 */

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <fstream>

#include "link_list_map.hpp"
#include "bst_map.hpp"
#include "avl_map.hpp"

double TestMap(Map<std::string, int> *map, const std::vector<std::string> &txt) {
    clock_t start, end;
    start = clock();

     for (auto w : txt) {
        if (map->contains(w)) {

            map->set(w, map->get(w) + 1);
        } else {
            map->add(w, 1);
        }
    }
    

    std::cout << "Total different words: " << map->size() << std::endl;
    std::cout << "Frequency of pride is " << map->get("pride") << std::endl;
    std::cout << "Frequency of prejudice is " << map->get("prejudice") << std::endl;


    end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    return duration;
}

int main()
{   
    std::vector<std::string> txt;
    std::string filename = "Pride And prejudice.txt";
    std::ifstream txt_file(filename);
    if (!txt_file.is_open()) {
        printf("fail to open %s\n", filename.c_str());
        return -1;
    }

    std::string line, word;
    printf("begin to read data from %s\n", filename.c_str());
    while (std::getline(txt_file, line))
    {
        std::istringstream istream(line);
        while (istream >> word)
        {
            txt.push_back(word);
        }
    }
    
    
    LinkListMap<std::string, int> link_list_map;
    double time1 = TestMap(&link_list_map, txt);
    std::cout << std::endl << "LinkeListMap: " << time1 << " s" << std::endl << std::endl;

    
    BSTMap<std::string, int> bst_map;
    double time2 = TestMap(&bst_map, txt);
    std::cout << std::endl << "BSTMap: " << time2  << " s"<<  std::endl;

    AVLMap<std::string, int> avl_map;
    double time3 = TestMap(&avl_map, txt);
    std::cout << std::endl << "AVLMap: " << time3  << " s"<<  std::endl;

   
    return 0;
}