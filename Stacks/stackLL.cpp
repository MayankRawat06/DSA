#include <iostream>
using namespace std;
template <typename T>
class Node
{
    public:
    T data;
    Node<T>* next;
    Node(T data)
    {
        this-> data= data;
        this-> next= NULL;
    }
};
template <typename T>
class Stack
{
    Node<T>* head;
    int size;
    public:
    Stack()
    {
        this-> head= NULL;
        size= 0;
    }
    void push(T element)
    {
        Node<T>* newNode= new Node<T>(element);
        if(head== NULL)
        {
            head= newNode;
        }
        else
        {
            newNode-> next= head;
            head= newNode;
        }
        size++;
    }
    bool isEmpty()
    {
        return size== 0;
    }
    int getSize()
    {
        return size;
    }
    T pop()
    {
        if(size== 0)
        {
            cout<<"Stack Empty!"<<endl;
            return 0;
        }
        else
        {
            Node<T>* temp= head;
            head= head-> next;
            T d= temp-> data;
            delete temp;
            size--;
            return d;
        }
    }
    T top()
    {
        return head-> data;
    }
};