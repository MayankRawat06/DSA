#include <iostream>
// #include "QueueArray.h"
#include "QueueLL.h"
using namespace std;
//Queue main
int main()
{
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.dequeue()<<endl; 
    cout<<q.isEmpty()<<endl;       
    return 0;
}
