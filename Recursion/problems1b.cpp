#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string removepi(string s)
{
    //remove pi 
    if(s.length()<= 1)
    {
        return s;
    }
    if(s[0]== 'p' && s[1]== 'i')
    {
        return "3.14" + removepi(s.substr(2));
    }
    else
    {
        return s[0] + removepi(s.substr(1));
    }
}
string removex(string s)
{
    //remove x
    if(s.length()== 0)
    {
        return s;
    }
    if(s[0]== 'x')
    {
        return removex(s.substr(1));
    }
    return s[0]+ removex(s.substr(1));
}
int stringtoint(string s)
{
    //convert string to int
    if(s.length()== 0)
    {
        return 0;
    }
    return (s[0]-'0')* pow(10, s.length()-1)+ stringtoint(s.substr(1));
}
string pairStar(string s)
{
    //pair star
    if(s.length()<= 1)
    {
        return s;
    }
    string smallAns= pairStar(s.substr(1));
    if(s[0]== smallAns[0])
    {
        string ss= "*" + smallAns;
        return s[0]+ ss;
    }
    return s[0] + smallAns;
}
void towerofhanoi(int n, char s, char a, char d)
{
    //tower of hanoi
    if(n== 1) 
    {
        cout<<"Move disk 1 from "<<s<< " to "<< d<< endl;
        return;
    }
    towerofhanoi(n-1, s, d, a);
    cout<<"Move disk "<<n<<" from "<<s<< " to "<< d<< endl;
    towerofhanoi(n-1, a, s, d);
}
int main()
{
    // string s;
    // cin>> s;
    // cout<<removepi(s)<<endl;
    // cout<<removex(s)<<endl;
    // cout<<stringtoint(s)<<endl;
    // cout<<pairStar(s)<<endl;
    char a, b, c;
    int n;
    cin>> n;
    towerofhanoi(n, 'a', 'b', 'c');
    return 0;
}


