/*
 * @Author: five-5
 * @Description: test set
 * @Date: 2019-04-02
 * @LastEditTime: 2019-04-02
 */

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "bst_set.hpp"
#include "link_list_set.hpp"


double test_set(set<std::string> *s) {
    clock_t start, end;
    
    start = clock();
    std::vector<std::string> txt = {"I","have","a","dream","I","want","to","be","more","and","more","powerful","to","face","everything","in","my","life"};
    std::cout << "total size : " << txt.size() << std::endl;
    for (auto w : txt) {
        s->add(w);
    }
    std::cout << "Total different words: " << s->size() << std::endl;

    end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    return duration;
}


int main()
{
    double time1, time2;
    
    BSTSet<std::string> word;
    time1 = test_set(&word);
    std::cout << "BSTSet time: " << time1 << " s"<< std::endl;

    LinkedListSet<std::string> wordl;
    time2 = test_set(&wordl);
    std::cout << "listset time: " << time2 << " s"<< std::endl;

    return 0;
}