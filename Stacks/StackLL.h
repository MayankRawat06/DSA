#include <iostream>
using namespace std;
// Stack implementation using Linked List as underlying data structure
template <typename T>
class Node
{
    public:
    T data;
    Node<T>* next= NULL;
    Node(T data)
    {
        this->data = data;
        this-> next= NULL;
    }
};
template <typename T>
class Stack
{
    Node<T>* head;
    int size; // number of elements present in the stack
    public:
    Stack()
    {
        head=NULL;
        size=0;
    }
    void push(T data)
    {
        Node<T>* newnode=new Node<T>(data);
        if(head==NULL)
        {
            head= newnode;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
        size++;
    }
    T top()
    {
        if(head==NULL)
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        return head-> data;
    }
    T pop()
    {
        if(head==NULL)
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        Node<T>* d= head;
        head= head-> next;
        T data= d-> data;
        delete d;
        size--;
        return data;
    }
    bool isEmpty()
    {
        return head== NULL;
    }
    int getSize()
    {
        return size;
    }
};