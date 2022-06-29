#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int mult(int n, int m)
{
    // multiplication
    if(m == 0) return 0;
    if(m== 1) return n;
    return n + mult(n, m-1);
}
int countzeroes(int n)
{
    // count zeroes
    if(n== 0) return 1;
    if(n/10 == 0 && n!= 0)
    {
        return 0;
    }
    int smallAns = countzeroes(n/10);
    if(n%10 == 0)
    {
        return 1+ smallAns;
    } 
    return smallAns;
}
double geometricsum(int k)
{
    // geometricsum
    if(k == 0) return 1;
    return (1/pow(2,k)) + geometricsum(k-1);
}
bool checkPalindrome(string s)
{
    // palindrome
    if(s.length()== 1) return true;
    else
    {
        if(s[0] == s[s.length()-1])
        {
            return checkPalindrome(s.substr(1, s.length()-2));
        }
        else
        {
            return false;
        }
    }
}
int sumofdigits(int n)
{
    //sum of digits
    if(n == 0)
    {
        return 0;
    }
    return n%10 + sumofdigits(n/10);
}
int main()
{
    // int m, n;
    // cin>> m>> n;
    // cout<< mult(m, n);
    // int n;
    // cin>> n;
    // cout<<countzeroes(n)<<endl;
    // int k;
    // cin>> k;
    // cout<< geometricsum(k)<<endl;
    // string s;
    // cin>> s;
    // cout<< checkPalindrome(s);
    int n;
    cin>> n;
    cout<<sumofdigits(n)<<endl;
    return 0;
}

