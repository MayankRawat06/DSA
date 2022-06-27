#include <iostream>
#include "Node.h"
using namespace std;
void printlist(Node* head)
{
    Node* temp= head;
    while(temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}
Node* takeinput()
{
    int data;
    cout<<"Enter\n";
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data!= -1)
    {
        Node* newnode= new Node(data);
        if(head== NULL)
        {
            head= newnode;  
            tail= newnode;
        }
        else
        {
            tail->next= newnode;
            tail= newnode;
            // or tail= tail->next;
        }
        cin>>data;
    }
    return head;
}
int main()
{
    Node* head= takeinput();
    printlist(head);
    return 0;
}