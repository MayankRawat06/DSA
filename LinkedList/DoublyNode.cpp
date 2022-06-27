#include <iostream>
using namespace std;
class Node
{
    // structure of doubly Node
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};