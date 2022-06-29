#include <iostream>
using namespace std;
int power(int x, int n)
{
    // to calculate the power of x to n
    // base case
    if (n == 0)
    {
        return 1;
    }
    // recursive case
    return x* power(x, n-1);
}
int digits(int n)
{
    // to calculate the number of digits in a number
    if (n/10== 0)      // base case
    {
        return 1;
    }
    return 1 + digits(n/10);   // recursive case
}
void printn(int n)
{
    // to print n numbers from 1 to n
    static int i= n+1;
    if (n == 1)   // base case
    {
        cout << i-1 << endl;
        return;
    }
    cout<<i-n<<" ";  // recursive case
    printn(n-1);
}
int fibo(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    return fibo(n-1)+ fibo(n-2);
}
bool issorted(int a[], int n)
{
    // to check if the array is sorted
    if(n== 0 || n== 1)
    {
        return true;     // base case
    }
    if(a[0]> a[1])
    {
        return false;    //iterative case
    }
    return issorted(a+1, n-1);
}
bool issorted2(int a[], int n)
{
    // to check if the array is sorted
    if(n== 0 || n== 1)
    {
        return true;     // base case
    }
    int smalloutput= issorted(a+1, n-1);
    if(!smalloutput)
    {
        return false;
    }
    if(a[0]> a[1])
    {
        return false;    //iterative case
    }
    else
    {
        return true;
    }
}
int sumofarray(int a[], int n)
{
    // to calculate the sum of an array
    if(n== 0)
    {
        return 0;
    }
    return a[0] + sumofarray(a+1 , n-1);
}
bool checknumber(int a[], int n, int x) 
{
    //To check the number in an array
    if(n== 0)
    {
        return false;
    }
    if(a[0]== x)
    {
        return true;
    }
    return checknumber(a+1, n-1, x);
}
int firstIndex(int a[], int n, int x)
{
    //To find the first index of a number in an array --first occurrence
    if(n == 0)
    {
        return -1;
    }
    if(a[0]==x)
    {
        return 0;
    }
    else
    {
        int smalloutput= firstIndex(a+1, n-1, x);
        if(smalloutput == -1)
        {
            return -1;
        }
        return 1+ smalloutput;
    }
} 
int lastIndex(int a[], int n, int x)
{
    //To find the last index of a number in an array --last occurrence
    if(n == 0)
    {
        return -1;
    }
    if(a[n-1]== x)
    {
        return n-1;
    }
    else
    {
        int smalloutput= lastIndex(a, n-1, x);
        if(smalloutput == -1)
        {
            return -1;
        }
        return smalloutput;
    }
}
int allIndex(int a[], int size, int x, int v[])
{
    //To find all the indices of a number in an array --all occurrences
    if(size == 0)
    {
        return 0;
    }
    int ans= allIndex(a+1, size-1, x, v);
    for(int i= ans-1; i>=0; i--)
    {
        v[i]= v[i]+1;
    }
    if(a[0]== x)
    {
        for(int i= size-1; i >=0; i--) 
        {
            v[i+1]= v[i];
        }
        v[0]= 0;
        return 1+ ans;
    }
    else
    {
        return ans;
    }
}
int allIndex1(int a[], int size, int x, int v[])
{
    if(size== 0) return 0;
    int ans= allIndex1(a, size-1, x, v);
    if(a[size-1]== x)
    {
        v[ans]= size- 1;
        return 1+ ans;
    }
    else
    {
        return ans;
    }
}
int main()
{
    int n, x;
    cin>>n;
    int* p= new int[n];
    int* v= new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }
    cin>>x;
    int ans= allIndex1(p, n, x, v);
    for(int i= 0; i< ans; i++)
    {
        cout<<v[i]<<" ";
    }
    delete[] p;
    delete[] v;
    return 0;
}