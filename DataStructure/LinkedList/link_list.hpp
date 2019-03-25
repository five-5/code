/*
 * @Author: five-5
 * @Description: 链表数据结构实现
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-25
 */

#ifndef LINK_LIST_H
#define LINK_LIST_H
#include <iostream>

template <typename T>
class LinkList {

 public:
    LinkList(){
        dummyhead_ = new Node(-1, nullptr);
        size_ = 0;
    }

    LinkList  &operator= (const LinkList & rhs){
        if (this == (&rhs)) {
            return *this;
        }
        Node *head1 = dummyhead_;
        Node *head2 = rhs.dummyhead_;

        while (head1->next_ && head2->next_ ) {
            head1->next_->e_ = head2->next_->e_;
            head1 = head1->next_;
            head2 = head2->next_;
        }
        head1->e_ = head2->e_;
        
        // head2更长
        if (head2->next_ != nullptr) {
            head2 = head2->next_;
            while (head2) {
                AddLast(head2->e_);
                head2 = head2->next_;
            }
        }

        // head1更长
        if (head1->next_ != nullptr) {
            Node *tmp = nullptr;
            while(head1->next_){
                tmp = head1->next_;
                head1->next_ = tmp->next_;
                delete tmp;
            }
        }

        return *this;
    }

    ~LinkList() {
        if (size_ != 0) {
            while (size_ != 0)
                Remove(0);
        }
        delete dummyhead_;
    }

    // 返回链表中元素的个数
   int size() const{
       return size_;
   }

   // 返回链表是否为空
   bool empty() const{
       return size_ == 0;
   }

   // 在链表的index(0-size)位置添加新的元素e
   // 在链表中不是一个常用的操作， 仅做练习用
   void Add(int index, T e) {
       if (index < 0 || index > size_) {
           std::cout << "Add failed: Illegal index." << std::endl;
       }
       
        Node *pre = dummyhead_;
        for (int i = 0; i < index; ++i) {
            pre = pre->next_;
        }

        //    Node *node = new Node(e);
        //    node->next = pre->next;
        //    pre->next = node;
        pre->next_ = new Node(e, pre->next_); // 被前一个结点所指向，构建参数中为需要指向的结点，这里也是替换的结点
        ++size_;
   }

    // 在链表头添加新的元素e
   void AddFirst(T e) {
       /*
        Node *node = new Node(e);
        node.next = head;
        head = node;

        head = new Node(e, head);
        ++size_;
       */
       Add(0, e);
   }

   // 在链表末尾添加新的元素e
   void AddLast(T e) {
       Add(size_, e);
   }

   // 获取链表的index(0-size)位置的元素e
   // 在链表中不是一个常用的操作， 仅做练习用
   T Get(int index) {
       if (index < 0 || index >= size_) {
           std::cout << "Get failed. Illegal index." << std::endl;
       }

       Node *cur = dummyhead_->next_;
       for (int i = 0; i < index; ++i){
           cur = cur->next_;
       }
       return cur->e_;
   }

   // 获取链表的第一个元素
   T GetFirst() {
       return Get(0);
   }

   // 获取链表的最后一个元素
   T GetLast() {
       return Get(size_ - 1);
   }

   // 修改链表的第index(0-size)位置的元素e
   // 在链表中不是一个常用的操作， 仅做练习用
   void set(int index, T e) {
       if (index < 0 || index >= size_) {
           std::cout << "Set failed. Illegal index." << std::endl;
       }
       
       Node *cur = dummyhead_->next_;
       for(int i = 0; i < index; ++i) {
           cur = cur->next_;
       }
       cur->e_ = e;
   }

   // 查找链表中是否有元素e
   bool Contains(T e) {
       Node *cur = dummyhead_->next_;
       while(cur != nullptr) {
           if (cur->e_ == e) {
               return true;
           }
           cur = cur->next_;
       }
       return false;
   }

    // 删除链表index位置的结点
    T Remove(int index) {
        if (index < 0 || index >= size_) {
           std::cout << "Remove failed. Illegal index." << std::endl;
       }

       Node *pre = dummyhead_;
       for (int i = 0; i < index; ++i) {
           pre = pre->next_;
       }
       Node *del_node = pre->next_;
       pre->next_= del_node->next_;
       T ret = del_node->e_;
       delete del_node;
       --size_;
       return ret;
    }

    // 删除链表第一个元素
    T RemoveFirst() {
        return Remove(0);
    }

    // 删除链表最后一个元素
    T RemoveLast() {
        return Remove(size_ - 1);
    }

    friend std::ostream & operator<< (std::ostream &out, const LinkList<T> &link_list) {
        /*Node *cur = link_list.dummyhead_->next_;
        while (cur != nullptr) {
            out << cur->e << "->"
            cur = cur->next_;
        }*/
        
        for (Node *cur = link_list.dummyhead_->next_; cur != nullptr; cur = cur->next_) {
            out << cur->e_ << "->";
        }

        out << "nullptr";
        return out;
    }

 private:
    class Node {
        public:
            Node(T e, Node *next):e_(e), next_(next){}
            Node (T e): e_(e), next_(nullptr){}

            T e_;
            Node *next_;
            
        friend std::ostream & operator<< (std::ostream &out, const Node &e) {
            out << e.e_;
            return out;
        }
    };

 private:
    int size_;
    Node *dummyhead_;
};
#endif