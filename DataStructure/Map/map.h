/*
 * @Author: five-5
 * @Description: the interface of map
 * @Date: 2019-04-02
 * @LastEditTime: 2019-04-04
 */

#ifndef MAP_H
#define MAP_H
template <typename K, typename V>
class Map{
 public:
    virtual void add(K key, V value) = 0;
    virtual V remove(K key) = 0;
    virtual bool contains(K key) = 0;
    virtual V get(K key) = 0;
    virtual void set(K key, V value) = 0;
    virtual int size() = 0;
    virtual bool empty() = 0;
};
#endif