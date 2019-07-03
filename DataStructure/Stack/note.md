<!--
 * @Author: five-5
 * @Description: 栈学习笔记
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-24
 -->

# 栈 FIFO
## 栈的实现
Stack<T>
- void Push(T)
- T Pop()
- T Top()
- int GetSize()
- bool IsEmpty()
均摊时间复杂度为：O(1)

## 栈的应用
1. undo（撤销）
 撤销时将栈顶元素删除

2. 程序调用的系统栈
 子过程子逻辑的调用

3. 括号匹配-编译器