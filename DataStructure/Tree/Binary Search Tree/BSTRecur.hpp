/*
 * @Author: five-5
 * @Description: the recursive implementation of bst
 * @Date: 2019-03-30
 * @LastEditTime: 2019-07-10 21:52:41
 */
#ifndef BSTRCUR_H
#define BSTRCUR_H
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <queue>

template<class src_type>
std::string Type2Str(src_type src) {
    std::stringstream ss;
    ss << src;
    std::string ret;
    ss >> ret;

    return ret;
}
template <typename T>
class BST{
 private :
    class Node {
        public :
            T e;
            Node *left, *right;
        Node(T elem, Node *left, Node *right):e(elem), left(left), right(right) {}
        Node(T elem):Node(elem, nullptr, nullptr){}
        Node(T elem, Node *left):e(elem), left(left), right(nullptr) {}
    };
    Node *root;
    int size_;
    
 public:
    BST(){
        root = nullptr;
        size_ = 0;
    }

    int size() {
        return size_;
    }

    bool empty() {
        return size_ == 0;
    }

    // 向sbt中添加新的元素e
    void Add(T e) {
        /*if (root == nullptr) {
            root = new Node(e);
            ++size_;
        } else {
            Add(root, e);
        }*/
        root = Add(root, e);
    }

    // 看二分搜索树是否包含元素e
    bool Contains(T e) {
        return Contains(root, e);
    }

    // 二分搜索树的前序遍历
    void PreOrder() {
        PreOrder(root);
    }

    // 非递归二分搜索树的前序遍历
    void PreOrderNR(){
        std::stack<Node *> stack_node;
        stack_node.push(root);
        while (!stack_node.empty()) {
            Node *cur = stack_node.top();
            stack_node.pop();
            std::cout << cur->e << std::endl;

            if (cur->right != nullptr) {
                stack_node.push(cur->right);
            }

            // 因为要先访问，所以需要后push进栈
            if (cur->left != nullptr) {
                stack_node.push(cur->left);
            }
        }
    }
    
    // 二分搜索树的中序遍历
    void InOrder() {
        InOrder(root);
    }

    // 非递归二分搜索树的中序遍历
    void InOrderNR(){
        std::stack<Node *> stack_node;
        Node *head = root;
        while (head != nullptr || !stack_node.empty()) {
            while (head) {
                stack_node.push(head);
                head = head->left;
            }
            head = stack_node.top();
            std::cout << head->e << std::endl;
            stack_node.pop();
            head = head->right;
        }
    }

    // 二分搜索树的后序遍历
    void PostOrder() {
        PostOrder(root);
    }

    // 二分搜索树的层次遍历
    void LevelOrder() {
        if (root == nullptr) {
            return;
        }
        std::queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *cur = q.front();
            q.pop();
            std::cout << cur->e << std::endl;
            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
    }

    // 查找最小值结点递归版
    T Minimum(){
        if (size_ == 0){
            std::cout << "Error delete. There is no node in the bst." << std::endl;
            return T();
        }
        return Minimum(root)->e;
    }

    // 查找最小值结点非递归版
    T MinimumNR(){
        if (size_ == 0){
            std::cout << "Error delete. There is no node in the bst." << std::endl;
            return T();
        }
        Node *pre = root;
        Node *cur = root;
        while (cur->left){
            pre = cur;
            cur = cur->left;
        }
        return cur->e;
    }

    // 查找最大值递归版
    T Maximum(){
        if (size_ == 0) {
            std::cout << "Error delete. There is no node in the bst." << std::endl;
            return T();
        }
        return Maximum(root)->e;        
    }

    // 查找最大值非递归版
    T MaximumNR(){
        if (size_ == 0){
            std::cout << "Error delete. There is no node in the bst." << std::endl;
            return T();
        }
        Node *pre = root;
        Node *cur = root;
        while (cur->right){
            pre = cur;
            cur = cur->right;
        }
        return cur->e;
    }

    // 从二分搜索树中删除最大值所在结点
    T RemoveMin() {
        T ret = Minimum();
        root = RemoveMin(root);
        return ret;
    }

    // 从二分搜索树中删除最小值所在结点
    T RemoveMax() {
        T ret = Maximum();
        root = RemoveMax(root);
        return ret;
    }
    
    // 从二分搜索树中删除元素e的结点
    void Remove(T e) {
       root = Remove(root, e);
    }

    friend std::ostream & operator<< (std::ostream &out, const BST &bst) {
        std::string res;
        bst.GengerateBSTString(bst.root, 0, res);
        out << res;
        return out;
    }
    
 private:
    // 向node为根的sbt中插入元素e,递归算法
    // 返回插入新结点后二分搜索树的根
     Node* Add(Node *node, T e) {
         /* void Add(Node *node, T e)
         // 1. 递归终止条件 [其实还不完美，nullptr也是一棵树，所以要直到nullptr才算到达了递归终止]
         if (node->e == e) {
            return;
         } else if (node->e < e && node->left == nullptr) {
             node->left = new Node(e);
             ++size_;
             return;
         } else if (node->e > e && node->right == nullptr){
             node->right = new Node(e);
             ++size_;
            return;
         }
         */
        if (node == nullptr) {
            ++size_;
            return new Node(e);
        }

        if (node->e > e) {
            node->left = Add(node->left, e);
        } else if (node->e < e){
            node->right = Add(node->right, e);
        }
        
        return node; // 二分搜索树插入元素之后的根还是这个node
    }

    // 看node为根的二分搜索树是否包含元素e，递归算法
    bool Contains(Node *node, T e) {
        if (node == nullptr) {
            return false;
        }

        if (node->e == e) {
            return true;
        } else if (node->e > e) {
            return Contains(node->left, e);
        } else {
            return Contains(node->right, e);
        }
    }

    // 前序遍历以node为根的二分搜索树，递归算法
    void PreOrder(Node *node) {
        
        if (node == nullptr) {
            return;
        }

        std::cout << node->e << std::endl;
        PreOrder(node->left);
        PreOrder(node->right);
    }

     // 前序遍历以node为根的二分搜索树的打印详细调用过程版本，递归算法
    void PreOrderDebug(Node *node, int depth) {
        
        if (node == nullptr) {
            std::cout << DepthString(depth) << "nullptr" << std::endl;
            return;
        }
        std::cout << DepthString(depth) << node->e << std::endl;
        PreOrderDebug(node->left, depth+1);
        PreOrderDebug(node->right, depth+1);
    }

    // 中序遍历以node为根的二分搜索树，递归算法
    void InOrder(Node *node) {
        
        if (node == nullptr) {
            return;
        }

        
        InOrder(node->left);
        std::cout << node->e << std::endl;
        InOrder(node->right);
    }

    // 后序遍历以node为根的二分搜索树，递归算法
    void PostOrder(Node *node) {
        
        if (node == nullptr) {
            return;
        }
  
        PostOrder(node->left);
        PostOrder(node->right);
        std::cout << node->e << std::endl;
    }

    // 生成depth长度的字符串（表示递归调用的层次）
    std::string DepthString(int depth) const{
        std::string str;
        for (int i = 0; i < depth + 1; ++i) {
            str += '-';
        }
        return str;
    }

    // 生成以node为根节点，深度为depth的描述二叉树的字符串
    void GengerateBSTString(Node *node, int depth, std::string &res) const{
        if (node == nullptr) {
            res += DepthString(depth) + "nullptr\n";
            return;
        }

        res += DepthString(depth) + Type2Str(node->e) + "\n";
        GengerateBSTString(node->left, depth+1, res);
        GengerateBSTString(node->right, depth+1, res);
    }
    
    // 寻找二分搜索树的最小元素
    Node* Minimum(Node *node) {
        if (node->left == nullptr) {
            return node;
        } else {
            return Minimum(node->left);
        }
    }

    // 寻找二分搜索树的最大元素
    Node* Maximum(Node *node) {
        if (node->right == nullptr) {
            return node;
        } else {
            return Maximum(node->right);
        }
    }

    // 删除掉以node为根的二分搜索树中的最小结点
    // 返回删除结点后新的二分搜索树的根
    Node* RemoveMin(Node *node) {
        if (node->left == nullptr) {
            Node *right_node = node->right;
            delete node;
            --size_;
            return right_node;
        }

        node->left = RemoveMin(node->left);
        return node;
    }

    // 删除掉以node为根的二分搜索树中的最小结点
    // 返回删除结点后新的二分搜索树的根
    Node* RemoveMax(Node *node) {
        if (node->right == nullptr) {
            Node *left_node = node->left;
            delete node;
            --size_;
            return left_node;
        }

        node->right = RemoveMax(node->right);
        return node;
    }

    // 删除以node为根的二分搜索树中值为e的结点，递归算法
    // 返回删除结点后新的二分搜索树的根
    Node* Remove(Node *node, T e) {
        if (node == nullptr) {
            return nullptr;
        }

        if (e < node->e) {
            node->left = Remove(node->left, e);
            return node;
        } else if (e > node->e) {
            node->right = Remove(node->right, e);
            return node;
        } else {
            // 待删除的结点左子树为空的情况
            if (node->left == nullptr) {
                Node *right_node = node->right;
                delete node;
                --size_;
                return right_node;
            }

            // 待删除的结点右子树为空的情况
            if (node->right == nullptr) {
                Node *left_node = node->left;
                delete node;
                --size_;
                return left_node;
            }

            // 左右子树都不为空的情况
            // 找到比待删结点大的最小结点，即待删除结点右子树的最小结点
            // 用这个结点顶替待删除结点的位置
            Node *new_node = Minimum(node->right);
            new_node->right = RemoveMin(node->right);
            new_node->left = node->left;
            delete node;
            return new_node;
        }
    }
};

#endif