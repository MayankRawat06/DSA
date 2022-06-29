#include <iostream>
using namespace std;
// Queue using an array
template <typename T>
class Queue
{
private:
    T* data= NULL;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;
public:
    Queue(int s)
    {
        data= new T[s];
        firstIndex= -1;
        nextIndex= 0;
        size= 0;
        capacity= s;
    }
    void enqueue(T element)
    {
        if(size== capacity)
        {
            T* newData= new T[2*capacity];
            int j= 0;
            for(int i= firstIndex; i< capacity; i++)
            {
                newData[j]= data[i];
                j++;
            }
            for(int i= 0; i< firstIndex; i++)
            {
                newData[j]= data[i];
                j++;
            }
            delete[] data;
            data= newData;
            firstIndex= 0;
            nextIndex= capacity;
            capacity= 2*capacity;
        }
            // cout<<"Queue is full"<<endl;
            // return;
        data[nextIndex]= element;
        if(size==0)
        {
            firstIndex= 0;
        }
        size++;
        nextIndex= (nextIndex+ 1)%capacity;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size== 0;
    }
    T front()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
    T dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        T element= data[firstIndex];
        firstIndex= (firstIndex+ 1)%capacity;
        size--;
        if(size==0)
        {
            firstIndex= -1;
            nextIndex= 0;
        }
        return element;
    }
};