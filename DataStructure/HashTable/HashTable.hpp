/*
 * @Author: five-5
 * @Date: 2019-07-12 15:55:16
 * @Description: 
 * @LastEditTime: 2019-07-12 17:28:13
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <map>
#include <functional>
#include <stdexcept>

template <typename K, typename V>
class HashTable{
 public:
    HashTable() {
        M = capacity[capacityIndex];
        size_ = 0;
        hashtable = new std::map<K,V>[M];
    }


    int size() {
        return size_;
    }

    void add(K key, V value) {
        std::map<K, V> tmp = hashtable[hash(key)];
        if (tmp.find(key) != tmp.end()) {
            tmp[key] = value;
        } else {
            tmp.emplace(key, value);
            ++size_;
        }

        if (size_ >= upperTol * M && capacityIndex + 1 < capacityLenth) {
            ++capacityIndex;
            resize(capacity[capacityIndex]);
        }
    }

    V remove(K key) {
        std::map<K, V> tmp = hashtable[hash(key)];
        V ret = V();
        if (tmp.find(key) != tmp.end()) {
            ret = tmp[key];
            tmp.erase(key);
            --size_;
            if (size_ < lowerTol * M && capacityIndex > 0) {
                --capacityIndex;
                resize(capacity[capacityIndex]);
            }
        }
        return ret;
    }

    void set(K key, V value) {
        std::map<K, V> tmp = hashtable[hash(key)];
        if (tmp.find(key) == tmp.end()) {
            throw std::runtime_error(key + "doesn't exist!");
        }

        tmp[key] = value;
    }

    bool contains(K key) {
        std::map<K, V> tmp = hashtable[hash(key)];
        return tmp.find(key) != tmp.end(); 
    }

    V get(K key) {
        return hashtable[hash(key)][key];
    }
 
 private:
    int hash(K key) {
        return (std::hash<K>{}(key) & 0x7fffffff) % M;
    }

    void resize(int newM) {
        std::map<K, V> *newHashTable = new std::map<K, V>[newM];

        int oldM = M;
        this->M = newM;
        for (int i = 0; i < oldM; ++i) {
           std::map<K, V> tmp = hashtable[i];
           for (auto it = tmp.begin(); it != tmp.end(); ++i) {
               newHashTable[hash(it->first)].emplace(it->first, it->second);
           } 
        }
        
        delete[] hashtable;
        hashtable = newHashTable;
    }

 private:
    static const int upperTol = 10;
    static const int lowerTol = 2;
    int capacityIndex = 0;
    static const int capacityLenth = 26;
    const int capacity[26] = {53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157, 98317, 196613, 393241, 786433, 1572869, 3145739, 6291469, 12582917, 25165843, 50331653, 100663319, 201326611, 402653189, 805306457, 1610612741};
    int M;
    int size_; 
    std::map<K, V> *hashtable;
};


# endif