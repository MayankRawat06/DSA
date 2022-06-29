#include <iostream>
#include <stack>
#include <string>

using namespace std;
//reverse a stack using another stack
stack<int> s1;
stack<int> s2;
void reverseusingtwo(stack<int> &s1, stack<int> &s2)
{
    if(s1.empty())
    {
        return;
    }
    int x= s1.top();
    s1.pop();
    reverseusingtwo(s1, s2);
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}
bool redundantParenthesis(string s)
{
    stack<char> st;
    
    for(int i=0; i<s.length(); i++)
    {
        int count= 0;
        if(s[i]== ')')
        {
            while(st.top()!= '(')
            {
                st.pop();
                count++;
            }
            if(count<= 1)
            {
                return true;
            }
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    return false;
}
void calculateSpan(int* price, int n, int* S)
{
    // Create a stack and push index of first
    // element to it
    stack<int> st;
    st.push(0);
 
    // Span value of first element is always 1
    S[0] = 1;
 
    // Calculate span values for rest of the elements
    for (int i = 1; i < n; i++) 
    {
        // Pop elements from stack while stack is not
        // empty and top of stack is smaller than
        // price[i]
        while (!st.empty() && price[st.top()] <= price[i])
        {
            st.pop();
        }
        // If stack becomes empty, then price[i] is
        // greater than all elements on left of it,
        // i.e., price[0], price[1], ..price[i-1].  Else
        // price[i] is greater than elements after
        // top of stack
        S[i] = (st.empty()) ? (i + 1) : (i - st.top());
 
        // Push this element to stack
        st.push(i);
    }
}
int postfix(string s)
{
    stack<int> st;
    int i=0;
    while(i<s.length())
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            int x= st.top();
            st.pop();
            int y= st.top();
            st.pop();
            if(s[i]=='+')
            {
                st.push(x+y);
            }
            else if(s[i]=='-')
            {
                st.push(x-y);
            }
            else if(s[i]=='*')
            {
                st.push(x*y);
            }
            else if(s[i]=='/')
            {
                st.push(x/y);
            }
        }
        i++;
    }
    return st.top();
}
int main()
{
    // int n;
    // cin >> n;
    // int t= n;
    // while(n--)
    // {
    //     int x;
    //     cin >> x;
    //     s1.push(x);
    // }
    // reverseusingtwo(s1, s2);
    // while(t--)
    // {
    //     cout<<s1.top()<<" ";
    //     s1.pop();
    // }
    // string s;
    // getline(cin, s);
    // cout<<redundantParenthesis(s);
    // int n;
    // cin>> n;
    // int* price= new int[n];
    // int* span= new int[n];
    // for(int i=0; i<n; i++)
    // {
    //     cin>> price[i];
    // }
    // calculateSpan(price, n, span);
    // for(int i=0; i<n; i++)
    // {
    //     cout<<span[i]<<" ";
    // }
    string s;
    getline(cin, s);
    cout<<postfix(s);
    return 0;
}
