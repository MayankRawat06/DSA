#include <iostream>
#include <queue>
using namespace std;
// reverse the queue order
void reverseQueue(queue<int> &q)
{
    if(q.empty())
    {
        return;
    }
    int x= q.front();
    q.pop();
    reverseQueue(q);
    q.push(x);
}   
int main()
{
    queue<int> q;
    int n;
    cin>>n;
    while(n--)
    {
        int x;  
        cin>>x;
        q.push(x);
    }
    reverseQueue(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
