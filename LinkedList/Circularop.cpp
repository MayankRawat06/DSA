#include <iostream>
#include "Node.h"
using namespace std;
Node* takeInput()
{
    int data;
    cout<<"Enter"<<endl;
    cin>>data;
    Node* head= NULL;
    Node* tail= NULL;
    while(data!= -1)
    {
        Node* newNode= new Node(data);
        if(head== NULL)
        {
            head= newNode;
            tail= newNode;
        }
        else
        {
            tail->next= newNode;
            tail= newNode;
        }
        cin>>data;
    }
    tail-> next= head;
    return head;
}
void print(Node* head)
{
    Node* temp= head;
    do
    {
        cout<<temp-> data<<" ";
        temp= temp-> next;
    }
    while(temp!= head);
    {
        cout<<endl;
    }
}
Node* addAtHead(Node* head)
{
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    Node* newNode= new Node(data);
    if(head== NULL)
    {
        head= newNode;
        head-> next= head;
    }
    else
    {
        newNode-> next= head;
        Node* temp= head;
        while(temp-> next!= head)
        {
            temp= temp-> next;
        }
        temp-> next= newNode;
        head= newNode;
    }
    return head;
}
Node* addAtTail(Node* head)
{
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    Node* newNode= new Node(data);
    Node* temp= head;
    if(head== NULL)
    {
        head= newNode;
        head-> next= head;
    }
    else
    {
        while(temp-> next!= head)
        {
            temp= temp-> next;
        }
        temp-> next= newNode;
        newNode-> next= head;
    }
    return head;
}
Node* deleteAtIthNode(Node* head, int i)
{
    if(i== 0)
    {
        Node* temp= head;
        while(temp-> next!= head)
        {
            temp= temp-> next;
        }
        temp-> next= head-> next;
        temp= head;
        head= head-> next;
        delete temp;
    }
    else 
    {
        int count= 0;
        Node* temp= head;
        while(count!= i-1 && temp-> next!= head)
        {
            temp= temp-> next;
            count++;
        }
        Node* temp2= temp-> next;
        temp-> next= temp2-> next;
        delete temp2;
    }
    return head;
}
int main()
{
    Node* head= takeInput();
    print(head);
    // Node* head= NULL;
    // head= addAtHead(head);
    // print(head);
    // head= addAtTail(head);
    // print(head);
    head= deleteAtIthNode(head, 3);
    print(head);
    // head= deleteAtIthNode(head, 5);
    // print(head);
    return 0;
}