#include <iostream>
#include "stackLL.cpp"
//#include "stackArray.cpp"
using namespace std;
//Stack main
int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '^')
        return 3;
    else
        return 0;
}
string infixToPostfix(string infix)
{
    string postfix = "";
    Stack<char> s;
    for(int i = 0; i < infix.length(); i++)
    {
        if(infix[i] >= '0' && infix[i] <= '9')
            postfix += infix[i];
        else if(infix[i] == '(')
            s.push(infix[i]);
        else if(infix[i] == ')')
        {
            while(s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while(!s.isEmpty() && precedence(s.top()) >= precedence(infix[i]))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while(!s.isEmpty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
int main()
{
    Stack<char> s;
    // s.push('a');
    // s.push('b');
    // s.push('c');
    // s.push('d');
    // s.push('e');
    // cout<<s.top()<<endl;
    // cout<<s.getSize()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.isEmpty()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.isEmpty()<<endl;
    // cout<<s.top()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.isEmpty()<<endl;
    cout<<infixToPostfix("(1+2)*(3+4)")<<endl;
    return 0;
}
