#include "BinaryTreeNode.h"
class BST {
    BinaryTreeNode<int> *root;
    BinaryTreeNode<int> * insert(BinaryTreeNode<int> *node, int data) {
        if(node == NULL) {
            BinaryTreeNode<int> *temp = new BinaryTreeNode<int>(data);
            return temp;
        }
        else if(data < node -> data) {
            node -> left = insert(node -> left, data);
        }
        else {
            node -> right = insert(node -> right, data);
        }
        return node;
    }
    bool hasData(int data, BinaryTreeNode<int> *node) {
        if(node == NULL) {
            return false;
        }
        if(node -> data == data) {
            return true;
        }
        if(data < node -> data) {
            return hasData(data, node -> left);
        }
        return hasData(data, node -> right);
    }
    int findMax(BinaryTreeNode<int> *node) {
        if(node == NULL) {
            return INT_MIN;
        }
        BinaryTreeNode<int> *temp = node;
        while(temp -> right != NULL) {
            temp = temp -> right;
        }
        return temp -> data;
    }
    int findMin(BinaryTreeNode<int> *node) {
        if(node == NULL) {
            return INT_MAX;
        }
        BinaryTreeNode<int> *temp = node;
        while(temp -> left != NULL) {
            temp = temp -> left;
        }
        return temp -> data;
    }
    BinaryTreeNode<int> * deleteElement(BinaryTreeNode<int> *node, int data) {
        if(node == NULL) {
            return NULL;
        }
        if(data < node -> data) {
            node -> left = deleteElement(node -> left, data);
        }
        else if(data > node -> data) {
            node -> right = deleteElement(node -> right, data);
        }
        else if(data == node -> data) {
            if(node -> left == NULL && node -> right == NULL) {
                delete node;
                return NULL;
            }
            else if(node -> left == NULL) {
                BinaryTreeNode<int> *temp = node -> right;
                node -> right = NULL;
                delete node;
                return temp;
            }
            else if(node -> right == NULL) {
                BinaryTreeNode<int> *temp = node -> left;
                node -> left = NULL;
                delete node;
                return temp;
            }
            else {
                // int maximum = findMax(node -> left);
                // node -> data = maximum;
                // node -> left = deleteElement(node -> left, maximum);
                int minimum = findMin(node -> right);
                node -> data = minimum;
                node -> right = deleteElement(node -> right, minimum);
            }
        }
        return node;
    }
    void printTree(BinaryTreeNode<int> *node) {
        if(node == NULL) {
            return;
        }
        cout << node -> data << " : ";
        if(node -> left != NULL) {
            cout << "L" << node -> left -> data << " ";
        }
        if(node -> right != NULL) {
            cout << "R" << node -> right -> data;
        }
        cout << endl;
        printTree(node -> left);
        printTree(node -> right);
    }
    public:
    BST() {
        root = NULL;
    }
    ~BST() {
        delete root;
    }
    void deleteData(int data) {
        root = deleteElement(root, data);
    }
    void insert(int data) {
        root = insert(root, data);
    }
    bool hasData(int data) {
        return hasData(data, root);
    }
    void printTree() {
        printTree(root);
    }
};