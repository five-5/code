/*
 * @Author: five-5
 * @Description: 
 * @Date: 2019-03-25
 * @LastEditTime: 2019-03-25
 */

#include "link_list.hpp"

int main()
{
    LinkList<int> link_list;
    for(int i = 0; i < 5; ++i) {
        link_list.AddFirst(i);
        std::cout << link_list << std::endl;
    }

    link_list.Add(2, 666);
    std::cout << link_list << std::endl;

    link_list.Remove(2);
    std::cout << link_list << std::endl;

    link_list.RemoveFirst();
    std::cout << link_list << std::endl;

    link_list.RemoveLast();
    std::cout << link_list << std::endl;
    
    return 0;
}