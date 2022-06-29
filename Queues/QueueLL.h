#include <iostream>
using namespace std;
// using LL
template <typename T> 
class Node
{
    public:
    T data;
    Node<T> * next;
    Node(T data)
    {
        this-> data= data;
        this-> next= NULL;
    }
};
template <typename T> 
class Queue
{
    private:
    Node<T> * head;
    Node<T> * tail;
    int size;
    public:
    Queue()
    {
        head= NULL;
        tail= NULL;
        size= 0;
    }
    void enqueue(T element)
    {
        Node<T> * newnode= new Node<T> (element);
        if(head== NULL)
        {
            head= newnode;
            tail= newnode;
        }
        else
        {
            tail-> next= newnode;
            tail= newnode;
        }
        size++;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size== 0;
    }
    T front()
    {
        if(size== 0)
        {
            return 0;
        }
        return head-> data;
    }
    T dequeue()
    {
        if(size== 0)
        {
            return 0;
        }
        Node<T> * d= head;
        head= head->next;
        T element= d-> data;
        delete d;
        size--;
        return element;
    }  
};