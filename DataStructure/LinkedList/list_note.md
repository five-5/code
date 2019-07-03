<!--
 * @Author: five-5
 * @Description: 链表笔记
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-29
 -->

# 链表
真正的动态数据结构，但是丧失了随机访问的能力

## 一、链表实现
- 添加操作
    Add(index, e)   O(n/2) = O(n)
    AddLast()       O(n)
    AddFirst()      O(1)
- 删除操作
    Remove(index)   O(n/2) = O(n)
    RemoveFirst()   O(1)
    RemoveLast()    O(n)
- 修改操作
    set()           O(n)
- 查找操作
    get(index)      O(n)
    contains(e)     O(n)

只对链表头操作及查链表头的时间复杂度为：O(1) => 栈

## 二、虚拟头结点
因为链表的增删都需要前一个结点，但是，链表头没有前一个结点所以特殊一点，设置一个虚拟头结点可以方便地统一操作


## 三、链表与递归
### (一) 链表的天然递归性
头结点->原始链表少一个结点的链表
基本：空结点

### (二) 递归
1. 递归问题主要先明确递归的语意，即要解决的问题
2. 从**宏观层面**去思考而不是陷入具体的细节
小问题组合形成问题的解
3. 例子
- ① 数组求和
> arr[0..n-1] </br>
sum[0..n-1] = arr[0] + sum[1..n-1] </br>
sum[1...n-1] = arr[1] + sum[2...n-1] </br>
sum[n-1..n-1] = arr[n-1] + sum[]&emsp;-> 基本问题

```c++
int sum(int *begin, int *end){
    if (begin == end)
        return 0;
    return *begin + sum(begin+1,end);
}
```
- ② 去除列表中的指定元素

> e->一个更短的链表（少一个结点）->nullptr </br>
语意：递归解决删除这个更小的链表中相应的元素 </br>
if e 要删除 直接返回更小的链表 </br>
else 返回e->更小链表

```c++
ListNode *RemoveAllElement(ListNode*head,int e {
    if (head == nullptr)
        return nullptr;

    head->next = RemoveAllElement(head->next, e);
    return (head->val == e)? head->next : head;
}
```
4. 递归调用的开销</br>
① 程序调用的系统栈 </br>
② 函数调用（需要查找函数的位置） + 系统栈空间  

5. 递归调试 </br>
**key**：递归深度，可以打印输出