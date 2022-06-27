#include <iostream>
#include "DoublyNode.cpp"
using namespace std;
Node* takeinput()
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
            tail-> next= newNode;
            newNode-> prev= tail;
            tail= newNode;
        }
        cin>>data;
    }
    return head;
}
void print(Node* head)
{
    Node* temp= head;
    while(temp!= NULL)
    {
        cout<<temp-> data<<" ";
        temp= temp-> next;
    }
    cout<<endl;
}
void printReverse(Node* head)
{
    Node* temp= head;
    while(temp-> next!= NULL)
    {
        temp= temp-> next;
    }
    while(temp!= NULL)
    {
        cout<<temp-> data<<" ";
        temp= temp-> prev;
    }
}
Node* addAtHead(Node* head)
{
    int data;
    cout<<"Enter"<<endl;
    cin>>data;
    Node* newNode= new Node(data);
    head-> prev= newNode;
    newNode-> next= head;
    head= newNode;
    return head;
}
Node* addAtTail(Node* head)
{
    int data;
    cout<<"Enter"<<endl;
    cin>>data;
    Node* newNode= new Node(data);
    Node* temp= head;
    while(temp-> next!= NULL)
    {
        temp= temp-> next;
    }
    temp-> next= newNode;
    newNode-> prev= temp;
    return head;
}
Node* deleteAtIthNode(Node* head, int i)
{
    int count= 0;
    Node* temp= head;
    if(i== 0)
    {
        head= head-> next;
        head-> prev= NULL;
        delete temp;
    }
    else
    {
        while(count!= i-1)
        {
            temp= temp-> next;
            count++;
        }
        Node* temp2= temp-> next;
        if(temp2-> next== NULL)
        {
            temp-> next= NULL;
            delete temp2;
        }
        else
        {
            temp-> next= temp2-> next;
            temp2-> next-> prev= temp;
            delete temp2;
        }
    }
    return head;
}

int main()
{
    Node* head= takeinput();
    print(head);
    // head= addAtHead(head);
    // print(head);
    // head= addAtTail(head);
    // print(head);
    // int i;
    // cout<<"Enter the index"<<endl;
    // cin>>i;
    // head= deleteAtIthNode(head, i);
    // print(head);
    printReverse(head);
    return 0;
}