#include <iostream>
using namespace std;
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data) {
        this->data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
    ~BinaryTreeNode() {
        delete this->left;
        delete this->right;
    }
};