/*
 * @Author: five-5
 * @Description: test for map
 * @Date: 2019-04-02
 * @LastEditTime: 2019-04-04
 */

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "link_list_map.hpp"
#include "bst_map.hpp"

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
    std::cout << "Frequency of I is " << map->get("I") << std::endl;
    std::cout << "Frequency of dream is " << map->get("dream") << std::endl;


    end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    return duration;
}

int main()
{   
    std::vector<std::string> txt = {"I","have","a","dream","I","want","to","be","more","and","more","powerful","to","face","everything","in","my","life"};
    
    
    LinkListMap<std::string, int> link_list_map;
    double time1 = TestMap(&link_list_map, txt);
    std::cout << std::endl << "TestMap: " << time1 << " s" << std::endl << std::endl;

    
    BSTMap<std::string, int> bst_map;
    double time2 = TestMap(&bst_map, txt);
    std::cout << std::endl << "BSTMap: " << time2  << " s"<<  std::endl;

   
    return 0;
}