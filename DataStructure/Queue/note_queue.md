<!--
 * @Author: five-5
 * @Description: 队列学习笔记
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-24
 -->

# 队列
## 队列的实现
- void push(T)
- T pop()
- T front()
- int size()
- bool empty()

ArrayQueue时间复杂度：
出队 O(n)
其他 O(1)
LoopQueue时间复杂度：
均为O(1)

## 循环队列
判空： front == tail队列为空
满：(tail + 1) % c== front


## 队列的应用
广度优先遍历

## 算法优化
 包含了数组队列和循环队列及其测试示例