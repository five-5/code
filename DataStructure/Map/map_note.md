<!--
 * @Author: five-5
 * @Description: map note
 * @Date: 2019-04-02
 * @LastEditTime: 2019-04-04
 -->
 
# 映射
理解：字典 单词->释意
</br>存储（键，值）数据对的数据结构（K，V）
</br>根据key找value

## 实现
Map<K,V>
- void add(K,V)
- V remove(K)
- bool contains(K)
- V get(K)
- void set(K, V)
- int size()
- bool empty()
时间复杂度：O(h): O(lgn) ~ O(n)

## 其他
- 有序映射中的键具有顺序性 
基于搜索树实现
- 无序映射中的键不具有顺序性
基于哈希表实现
- 键可重复的多重映射 
【作家与其作品间的映射】
- 基于映射去封装集合
集合为value为空的映射