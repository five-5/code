<!--
 * @Author: five-5
 * @Description: note of set
 * @Date: 2019-04-02
 * @LastEditTime: 2019-04-02
 -->

# 集合
无重复

## 集合实现接口
Set<T>
- void add(T)：不能添加重复元素
- void remove(T)
- bool contains(T)
- int size()
- bool empty()

## 应用
1. 客户统计
2. 词汇量统计

## 多重集合
集合中的元素可以重复

## 其他
1. 有序集合中的元素具有顺序性【基于搜索树实现的】
2. 无序集合中的元素没有顺序性【基于哈希表的实现】