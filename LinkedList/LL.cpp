#include <iostream>
#include "Node.cpp"
using namespace std;
//NAIVE IMPLEMENTATION
// Node * takeinput()
// {
//     int data;
//     cout<<"Enter \n";
//     cin>>data;
//     Node* head= NULL;
//     while(data!= -1)
//     {
//         Node* newnode= new Node(data);
//         if(head== NULL)
//         {
//             head= newnode;
//         }
//         else
//         {
//             Node* temp= head;
//             while(temp->next!= NULL)
//             {
//                 temp= temp->next;
//             }
//             temp->next= newnode;
//         }
//         cin>>data;
//     }
//     return head;
// }
Node* insertNode(Node* head, int data, int index)
{
    //insertion of node at ith index
    int count= 0;
    Node* newnode= new Node(data);
    if(index== 0)
    {
        newnode-> next= head;
        head= newnode;
        return head;
    }
    Node* temp= head;
    while(count< index- 1 && temp!= NULL)
    {
        temp= temp->next;
        count++;
    }
    if(temp!= NULL)
    {
        newnode-> next= temp-> next;
        temp-> next= newnode;
    }
    return head;
}
Node* deleteNode(Node* head, int index)
{
    //deletion of node at ith index
    int count= 0;
    Node* temp= head;
    if(index== 0)
    {
        head= head-> next;
        delete temp;
        return head;
    }
    while(count< index-1 && temp!= NULL)
    {
        temp= temp->next;
        count++;
    }
    if(temp!= NULL && temp->next!= NULL)
    {
        Node* temp2= temp->next;
        temp->next= temp2->next;
        delete temp2;
    }
    return head;
}
Node* deleteNoderec(Node* head, int index)
{
    if(index==0)
    {
        Node* temp= head;
        head= head-> next;
        delete temp;
        return head;
    }
    else
    {
        Node* temp= head;
        while(temp!= NULL)
        {
            if(index== 1)
            {
                Node*temp2= temp->next;
                temp-> next= temp2-> next;
                delete temp2;
            }
            index--;
            temp= temp->next;
        }
    }
    return head;
}
int countlength(Node* head)
{
    // find the length of the linked list iteratively
    int count=0;
    Node* temp= head;
    while(temp!= NULL)
    {
        count++;
        temp= temp->next;
    }
    return count;
}
int countlengthrec(Node* head)
{
    //find the length of the linked list recursively
    if(head== NULL)
    {
        return 0;
    }
    else
    {
        return 1+ countlengthrec(head->next);
    }
}
void printlist(Node* head)
{
    Node* temp= head;
    while(temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<"\n";
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
void findNode(Node* head, int index)
{
    //find the ith node
    Node* temp= head;
    int count=0;
    while(temp!= NULL)
    {
        if(count== index)
        {
            cout<<"Node at index "<<index<<" is "<<temp->data<<endl;
            break;  
        }
        temp= temp->next;
        count++;
    }
    if(temp== NULL)   
    cout<<"Node not found\n";
}
Node* insertNoderec(Node* head, int data, int index)
{
    //insertion of node at ith index recursively
    if(index== 0 || head == NULL)
    {
        Node* newnode= new Node(data);  
        newnode-> next= head;
        head= newnode;
        return head;
    }
    else
    {
        Node* temp= head;   
        while(temp!= NULL)
        {
            if(index== 1)
            {
                Node* newnode= new Node(data);
                newnode-> next= temp-> next;
                temp-> next= newnode;
                return head;
            }
        }
        return insertNoderec(temp-> next, data, index-1);
    }
}
void getIndex(Node* head, int data)
{
    //find the index of the node
    Node* temp= head;
    int count=0;
    while(temp!= NULL)
    {
        if(temp->data== data)
        {
            cout<<count<<endl;
            break;
        }
        temp= temp->next;
        count++;
    }
    if(temp== NULL)
    cout<<"Node not found\n";
}
Node* appendNtofirst(Node* head, int n, int l)
{
    //append n nodes from the last to the first node
    Node* temp= head;
    int i= 1;
    int count= l- n;
    while(i< count)
    {
        temp= temp->next;   
        i++;
    }
    Node* head2= temp->next;
    temp->next= NULL;
    Node* temp2= head2;
    while(temp2-> next!= NULL)
    {
        temp2= temp2->next;
        i++;
    }
    temp2->next= head;
    return head2;
}
Node* deleteDuplicates(Node* head)
{
    //delete duplicates from the linked list
    if(head== NULL || head->next== NULL)
    {
        return head;
    }
    Node* temp1= head;
    Node* temp2= head-> next;
    while(temp2!= NULL)
    {
        if(temp1->data== temp2->data)
        {
            Node* d= temp2;
            temp2= temp2->next;
            delete d;
        }
        else
        {   
            temp1-> next= temp2;
            temp1= temp2;
            temp2= temp2->next;
        }
    }
    temp1->next= temp2;
    return head;
}
void printreverse(Node* head)
{
    //print the linked list in reverse order
    if(head== NULL)
    {
        return;
    }
    else
    {
        printreverse(head->next);
        cout<<head->data<<" ";
    }
}
Node* reverse(Node* head)
{
    //reverse the linked list iteratively
    if(head== NULL || head->next== NULL)
    {
        return head;
    }
    Node* prev= NULL;
    Node* next= NULL;
    while(head!=NULL)
    {
        next= head->next;
        head-> next= prev;
        prev= head;
        head= next;
    }
    head= prev;
    return head;
}
bool palindrome(Node* head)
{
    //check if the linked list is palindrome
    if(head== NULL || head->next== NULL)
    {
        return true;
    }
    else
    {
        int l= countlength(head);
        int mid= 0;
        (l%2==0)? mid= l/2: mid= l/2+1;
        Node* temp= head;
        int i= 0;
        while(i< mid)
        {
            temp= temp->next;
            i++;
        }
        Node* head2= temp->next;
        temp->next= NULL;
        head2= reverse(head2);
        temp= head;
        while(head2!= NULL)
        {
            if(head2->data!= temp->data)
            {
                return false;
            }
            head2= head2->next;
            temp= temp->next;
        }   
        return true;
    }        
}
int getNodeindex(Node* head, int data)
{
    //get the index of the node
    Node* temp= head;
    int count=0;
    while(temp!= NULL)
    {
        if(temp->data== data)
        {
            return count;
        }
        temp= temp->next;
        count++;
    }
    return -1;
}
int findmiddle(Node* head)
{
    //find the middle element of the linked list    
    if(head==NULL || head->next== NULL)
    {
        return -1;
    }
    Node* temp= head;
    int i= 1;
    int l= countlength(head);
    int mid= 0;
    (l%2==0)? mid= l/2: mid= l/2+1;
    while(i< mid)
    {
        temp= temp->next;
        i++;
    }
    return temp->data;
}
Node* merge(Node* head1, Node* head2)
{
    //merge two sorted linked lists
    Node* fhead= NULL;
    Node* ftail= NULL;
    //if head1 or head2 is empty
    if(head1== NULL)
    {
        return head2;
    }
    if(head2== NULL)
    {
        return head1;
    }
    //compare the data of the head1 and head2 to fix fhead
    if(head1->data< head2->data)
    {
        fhead= head1;
        ftail= head1;
        head1= head1-> next;
    }
    else
    {
        fhead= head2;
        ftail= head2;
        head2= head2->next;
    }
    //further comparing the data of the head1 and head2 and just add the smaller one to the ftail
    while(head1!= NULL && head2!= NULL)
    {
        if(head1->data< head2->data)
        {
            ftail->next= head1;
            ftail= ftail->next;
            head1= head1->next;
        }
        else
        {
            ftail->next= head2;
            ftail= ftail->next;
            head2= head2->next;
        }
    }
    //if any of the two list becomes empty
    if(head1== NULL)
    {
        ftail->next= head2;
    }
    else
    {
        ftail->next= head1;
    }
    return fhead;
}
Node* mergeSort(Node* head)
{
    //merge sort the linked list (recursive)
    //if the linked list is empty or has only one node
    if(head== NULL || head->next== NULL)
    {
        return head;
    }
    //find the middle element
    int l= countlength(head);
    int mid= 0;
    (l%2==0)? mid= l/2: mid= l/2+1;
    //break the linked list into two parts
    Node* temp= head;
    int i= 1;
    while(i< mid)
    {
        temp= temp->next;
        i++;
    }
    Node* head2= temp->next;
    temp->next= NULL;
    //recursively sort the two parts
    head= mergeSort(head);
    head2= mergeSort(head2);
    //merge the two sorted parts
    head= merge(head, head2);
    return head;
}
Node* reverserecursive(Node* head)
{
    //reverse the linked list recursively
    if(head== NULL || head->next== NULL) //base case
    {
        return head;
    }
    Node* temp= head->next;  //recursive case
    head->next= NULL;
    Node* head2= reverserecursive(temp);
    temp->next= head;  //small case
    return head2;
}
// Pair reverseLL(Node* head)
// {
//     //reverse the linked list recursively using head and tail pointers
//     if(head== NULL || head->next== NULL) //base case
//     {
//         Pair ans;
//         ans.head= head;
//         ans.tail= head;
//         return ans;
//     }
//     Pair smallans= reverseLL(head->next);
//     smallans.tail->next= head;
//     head->next= NULL;
//     Pair ans;
//     ans.head= smallans.head;
//     ans.tail= head;
//     return ans;
// }
// Node* reversex(Node* head)
// {
//     // call the reverseLL function and return the head of the reversed linked list
//     return reverseLL(head).head; 
// }
Node* reverseiter(Node* head)
{
    //reverse the linked list iteratively
    Node* curr= head;
    Node* next= NULL;
    Node* prev= NULL;
    while(curr!= NULL)
    {
        next= curr-> next;
        curr->next= prev;
        prev= curr;
        curr= next;
    }
    return prev;
}
int getNoderec(Node* head, int data)
{
    //get a node index in the LL recursively 
    if(head== NULL)
    {
        return -1;
    }
    if(head-> data == data)
    {
        return 0;
    }
    return 1 + getNoderec(head-> next, data);
}
Node* segregateEvenOdd(Node* head)
{
    //segregate the even and odd nodes in the linked list
    if(head== NULL || head->next== NULL)
    {
        return head;
    }
    Node* evenhead= NULL;
    Node* eventail= NULL;
    Node* oddhead= NULL;
    Node* oddtail= NULL;
    Node* temp= head;
    while(temp!= NULL)
    {
        if(temp->data%2== 0)
        {
            if(evenhead== NULL)
            {
                evenhead= temp;
                eventail= temp;
            }
            else
            {
                eventail->next= temp;
                eventail= temp;
            }
        }
        else
        {
            if(oddhead== NULL)
            {
                oddhead= temp;
                oddtail= temp;
            }
            else
            {
                oddtail->next= temp;
                oddtail= temp;
            }
        }
        temp= temp->next;
    }
    if(oddhead== NULL)
    {
        return evenhead;
    }
    eventail->next= NULL;
    oddtail-> next= evenhead;
    return oddhead;
}
Node* skipMdeleteN(Node* head, int M, int N)
{
    //skip M delete N nodes in the linked list
    if(head== NULL || head->next== NULL)
    {
        return head;
    }
    Node* temp1= head;
    Node* temp2= head;
    int count;
    while(temp1!= NULL)
    {
        for(count = 1; count< M && temp1!= NULL; count++)
        {
            temp1= temp1->next;
        }
        if(temp1== NULL)
        {
            break;
        }
        if(M== 0)
        {
            temp2= temp1;
        }
        else
        temp2= temp1-> next;
        for(count= 1; count<= N && temp2!= NULL; count++)
        {
            Node* del= temp2;
            temp2= temp2->next;
            delete del;
        }
        temp1->next= temp2;
        temp1= temp2;
    }
    return head;
}
Node* swapNode(Node* head, int x, int y)
{
    //swap two nodes in the linked list
    if(head== NULL || head->next== NULL)
    {
        return head;
    }
    if(x== y)
    {
        return head;
    }
    else if(x> y)
    {
        int temp= x;
        x= y;
        y= temp;
    }   
    Node* c1= head;
    Node* c2= head;
    Node* p1= NULL;
    Node* p2= NULL;
    int count= 0;
    while(c1!= NULL && count< x)
    {
        p1= c1;
        c1= c1->next;
        count++;
    }
    count= 0;
    while(c2!= NULL && count< y)
    {
        p2= c2;
        c2= c2->next;
        count++;
    }
    if((x== 0 || y== 0) && (x- y == 1 || y- x == 1))
    {
        c1-> next= c2-> next;
        c2-> next= c1;
        head= c2;
    }
    else if(x== 0 || y== 0)
    {
        p1= c1-> next;
        c1-> next= c2-> next;
        c2-> next= p1;
        p2-> next= c1;
        head= c2;
    }
    else if(x- y == 1 || y- x == 1) 
    {
        p1->next= c2;
        c1-> next= c2-> next;
        c2-> next= c1;
    }
    else
    {
        Node* n1= c1-> next;
        p1->next= c2;
        p2->next= c1;
        c1-> next= c2-> next;
        c2-> next= n1;
    }
    return head;
}
Node* swapNodeval(Node* head, int k)
{
    //swap node values 
    if(head== NULL || head-> next== NULL)
        {
            return head;
        }
        int l= countlength(head);
        if(k== l)
        {
            k= 0;
        }
        Node* temp= head;
        Node* c1= NULL;
        Node* c2= NULL;
        int count= 0;
        while(temp!= NULL)
        {
            if(count== k-1)
            {
                c1= temp;
            }
            if(count== l-k)
            {
                c2= temp;
                break;
            }
            temp= temp-> next;
            count++;
        }
        int swap= c1-> data;
        c1-> data= c2-> data;
        c2-> data = swap;
        return head;
}
Node* kreverse(Node* head, int k)
{
    //reverse in group of k
    if(k== 0) 
    {
        return head;
    }
    int count= 0;
    Node* curr= head;
    Node* next= NULL;
    Node* prev= NULL;
    while(curr!= NULL && count< k)
    {
        next= curr-> next;
        curr-> next= prev;
        prev= curr;
        curr= next;
        count++;
    }
    if(next!= NULL)
    head-> next= kreverse(curr, k);
    return prev;
    // if given to not reverse the node when remaining length exceeds k
    //  if(countlength(next)< k)
    //     {
    //         head-> next= curr;
    //     }
    //     else
    //     {
    //         head-> next= kreverse(curr, k);
    //     }
    //     return prev;
}
Node* BubbleSort(Node* head)
{
    //bubble sort
    for(int i= 0; i< countlength(head); i++)
    {
        Node* curr= head;
        Node* next= NULL;
        Node* prev= NULL;
        while(curr-> next!= NULL)
        {
            next= curr-> next;
            if(curr-> data> next-> data)
            {
                curr-> next= next-> next;
                next-> next= curr;
                if (prev== NULL)
                {
                    head= next;
                }
                else
                {
                    prev-> next= next;
                }
                prev= next;
            }
            else
            {
                prev= curr;
                curr= next;
            }
        }
    }
    return head;
}
int getmid(Node* head)
{
    //get the mid without using length
    Node* slow= head;
    Node* fast= head-> next;
    while(fast!= NULL && fast-> next!= NULL)
    {
        slow= slow-> next;
        fast= fast-> next-> next;
    }
    return slow->data;
}
Node* deleteDuplicatesUnsorted(Node* head)
{
    if(head== NULL || head-> next== NULL)
    {
        return head;
    }
    head= mergeSort(head);
    Node* t1= head;
    Node* t2= head-> next;
    while(t2!= NULL)
    {
        if(t1-> data== t2-> data)
        {
            Node* d= t2;
            t2= t2-> next;
            delete d;
        }
        else
        {
            t1-> next= t2;
            t1= t2;
            t2= t2-> next;
        }
    }
    t1-> next= t2;
    return head;
}
Node* mergeInBetween(Node* list1, int a, int b, Node* list2) 
{
    Node* temp= list1;
    //reaching till athh node
    for(int i= 0; i< a-1; i++)
    {
        temp= temp-> next;
    }
    //storing next of a node before ath node 
    Node* temphead1= temp-> next;
    temp-> next= list2;   //putting list2 in place of list running from ath node
    temp= temp-> next;    
    //moving till bth node
    for(int i= a; i< b; i++)
    {
        temphead1= temphead1-> next;
    }
    Node* temphead2= temphead1-> next;
    temphead1-> next= NULL;
    Node* newtemp= list1;
    while(newtemp-> next!= NULL)
    {
        newtemp= newtemp-> next;
    }
    newtemp-> next= temphead2;
    while(temphead1!= NULL)
    {
        Node* x= temphead1;
        temphead1= temphead1-> next;
        delete x;
    }
    return list1;
}
Node* insertAtMid(Node* head, int c)
{
    // insert a node at the middle of the linked list
    int count= countlength(head);
    Node* temp= head;
    Node* prev= NULL;
    int i=0;
    while(i< count/2)
    {
        prev= temp;
        temp= temp-> next;
        i++;
    }
    Node* newNode= new Node(c);
    newNode-> next= temp;
    prev-> next= newNode;
    return head;
}
Node* deleteNode1(Node* head, int c)
{
    Node* temp= head;
    if(head-> data== c)
    {
        head= head-> next;
        delete temp;
    }
    else
    {
        while(temp-> next!= NULL && temp-> next-> data!= c)
        {
            temp= temp-> next;
        }
        if(temp-> next!= NULL)
        {
            Node* temp2= temp-> next;
            temp-> next= temp-> next-> next;
            delete temp2;
        }
    }
    return head;
}
int main()
{
    Node * head= takeinput();
    printlist(head);
    // Node * head2= takeinput();
    // printlist(head2);
    // mergeInBetween(head1, 3, 4, head2);
    // printlist(head1);
    // head= deleteNode1(head, 2);
    // printlist(head);
    head= insertAtMid(head, 5);
    printlist(head);
    return 0;
}
