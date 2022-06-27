#include <iostream>
using namespace std;
template <typename T>
class Stack
{
    private:
    T* data= NULL;
    int nextIndex;
    int capacity;
    public:
    Stack()
    {
        data= new T[4];
        nextIndex= 0;
        capacity= 4;
    }
    int getSize()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        return nextIndex== 0;
    }
    void push(T element)
    {   
        if(nextIndex== capacity)
        {
            T* newData= new T(2* capacity);
            capacity*= 2;
            for(int i= 0; i< nextIndex; i++)
            {
                newData[i]= data[i];
            }
            delete [] data;
            data= newData;
        }
        data[nextIndex]= element;
        nextIndex++;
    }
    T pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Empty!"<<endl;
            return 0;
        }
        else
        {
            nextIndex--;
            return data[nextIndex];
        }
    }
    T top()
    {
        if(nextIndex== 0)
        {
            cout<<"Stack Empty!"<<endl;
            return 0;
        }
        return data[nextIndex- 1];
    }
};