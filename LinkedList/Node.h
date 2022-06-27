#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int d)
    {
        data = d;
        this-> next = NULL;
    }
};
