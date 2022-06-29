#include <iostream>
#include <string>  
#include <vector>
#include <math.h>
using namespace std;
int getStringLength(string s)
{
    //get string length
    if(s[0]== '\0')
    {
        return 0;
    }
    return 1+ getStringLength(s.substr(1));
}
string replaceChar(string s, char a, char x)
{
    //replace char
    if(s[0]== '\0')
    {
        return s;
    }
    if(s[0]== a)
    {
        return x+ replaceChar(s.substr(1), a, x);
    }
    return s[0] + replaceChar(s.substr(1), a, x);
}
string removeDuplicates(string s)
{
    //remove consecutive duplicates
    if(s[0]== '\0')
    {
        return s;
    }
    if(s[0]== s[1])
    {
        return removeDuplicates(s.substr(1));
    }
    return s[0] + removeDuplicates(s.substr(1));
}
void merge(int a[], int mid, int n)
{
    //merge two sorted arrays
    int i= 0;
    int j= mid;
    int k= 0;
    int temp[n];
    while(i< mid && j< n)
    {
        if(a[i]> a[j])
        {
            temp[k]= a[j];
            j++;
        }
        else
        {
            temp[k]= a[i];
            i++;
        }
        k++;
    }
    while(i< mid)
    {
        temp[k]= a[i];
        i++;
        k++;
    }
    while(j< n)
    {
        temp[k]= a[j];
        j++;
        k++;
    }
    for(int i= 0; i< n; i++)
    {
        a[i]= temp[i];
    }
}
void mergeSort(int a[], int n)
{
    //merge sort
    if(n<= 1)
    {
        return;
    }
    int mid = n/2;
    mergeSort(a, mid);
    mergeSort(a+mid, n-mid);
    merge(a, mid, n);
}
void partition(int a[], int pivot, int n)
{
    //partition
    int i= 0;
    int j= n-1;
    while(i< j)
    {
        while(a[i]<= pivot)
        {
            i++;
        }
        while(a[j]> pivot)
        {
            j--;
        }
        if(i< j)
        {
            int temp= a[i];
            a[i]= a[j];
            a[j]= temp;
        }
    }
}
void QuickSort(int a[], int n)
{
    //quick sort
    if(n<= 1)
    {
        return;
    }
    int x= a[0];
    int count= 0;
    for(int i= 0; i< n; i++)
    {
        if(a[i]< x)
        {
            count++;
        }
    }
    int temp= a[count];
    a[count]= a[0];
    a[0]= temp;
    partition(a, count, n);
    QuickSort(a, count);
    QuickSort(a+count +1, n- count- 1);
}
int subs(string in, string out[])
{
    //return the possible subsequences
    if(in.empty()) 
    {
        out[0]= "";
        return 1;
    }
    int smallOut= subs(in.substr(1), out);
    for(int i= 0; i< smallOut; i++)
    {
        out[i+ smallOut]= in[0] + out[i];
    }
    return smallOut* 2;
}
int key(vector<char> keypad[], int x, vector<string> p, int &si)
{
    //return the possible combinations on keypad
    if(x== 0 || x== 1)
    {
        p.push_back("");
        return 1;
    }
    int smallOut= key(keypad, x/10, p, si);
    si= smallOut;
    int k= 0;
    for(int i= 0; i< smallOut; i++)
    {
        for(int j= 1; j< keypad[x%10].size(); j++)
        {
            p.push_back(keypad[x%10][j]+ p[i]);
        }
    }
    return smallOut* keypad[x%10].size();
}

int main()
{
    // string s;
    // getline(cin, s);
    // // cout<<getStringLength(s)<<endl;
    // // char a, x;
    // // cin>> a>> x;
    // // cout<< replaceChar(s, a, x)<<endl;
    // cout<< removeDuplicates(s)<<endl;
    // int n;
    // cin>> n;
    // int *p= new int[n];
    // for(int i= 0; i< n; i++)
    // {
    //     cin>> p[i];
    // }
    // mergeSort(p, n);
    // for(int i= 0; i< n; i++)
    // {
    //     cout<< p[i]<< " ";
    // }

    // int n;
    // cin>> n;
    // int *p= new int[n];
    // for(int i= 0; i< n; i++)
    // {
    //     cin>> p[i];
    // }
    // QuickSort(p, n);
    // for(int i= 0; i< n; i++)
    // {
    //     cout<< p[i]<< " ";
    // }
    // string s;
    // getline(cin, s);
    // int ps= pow(2, s.size());
    // string *p= new string[ps];
    // int count= subs(s, p);
    // for(int i= 0; i< count; i++)
    // {
    //     cout<< p[i]<<endl;
    // }
     vector<char> keypad[] =
    {
        {}, {},        // 0 and 1 digit don't have any characters associated
        { 'a', 'b', 'c' },
        { 'd', 'e', 'f' },
        { 'g', 'h', 'i' },
        { 'j', 'k', 'l' },
        { 'm', 'n', 'o' },
        { 'p', 'q', 'r', 's'},
        { 't', 'u', 'v' },
        { 'w', 'x', 'y', 'z'}
    };
    int x, *si= 0;
    cin>> x;
    vector<string> p;
    int count= key(keypad, x, p, *si);
    cout<<count;
    for(int i= *si-1; i< count; i++)
    {
        cout<< p[i]<<endl;
    }
    return 0;
}