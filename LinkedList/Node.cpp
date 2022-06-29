#include <iostream>
using namespace std;
// Structure of Node
class Node{
public:
    int data;
    Node* next= NULL;
    Node(int data)
    {
        this->data = data;
        this-> next= NULL;
    }
};