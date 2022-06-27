#include <iostream>
#include <vector>
using namespace std;
void printVector(int v[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void partition(int v[], int n, int count) 
{
    int p= v[count];
    int i= 0, j= n-1;
    while(i< j)
    {
        while(v[i]<= p)
        {
            i++;
        }
        while(v[j]> p)
        {
            j--;
        }
        if(i< j)
        {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
}
void quickSort(int v[], int n)
{
    if(n<= 1)
        return;
    int pivot= v[0];
    int count= 0;
    for(int i= 0; i< n; i++)
    {
        if(v[i]< pivot)
        {
            count++;
        }
    }
    int temp= v[count];
    v[count] = v[0];
    v[0] = temp;
    partition(v, n, count);
    quickSort(v, count);
    quickSort(v+ count+ 1, n-count-1);
}
void insertionSort(int v[], int n) 
{
    //Insertion sort
    int key;
    for(int i= 1; i<n; i++)
    {
        key= v[i];
        int j= i-1;
        while(j>= 0 && v[j]> key)
        {
            v[j+1]= v[j];
            j--;
        }
       
        v[j+1]= key;
        printVector(v, n);
    }
}

void takeInput(int v[], int n) 
{
    cout<<"Enter array elements"<<endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> v[i];
    }
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
void selectionSort(int v[], int n)
{
    //selection sort
    for(int i= 0; i< n- 1; i++)
    {
        for(int j= i+ 1; j< n; j++)
        {
            if(v[j]< v[i])
            {
                int temp= v[i];
                v[i]= v[j];
                v[j]= temp;
            }
        }
    }
}
void countSort(int v[], int n)
{
    //count sort
    int max= v[0];
    for(int i= 1; i< n; i++)
    {
        if(v[i]> max)
        {
            max= v[i];
        }
    }
    int* count= new int[max+ 1];
    for(int i= 0; i< max+ 1; i++)
    {
        count[i]= 0;
    }
    for(int i= 0; i< n; i++)
    {
        count[v[i]]++;
    }
    for(int i= 1; i< max+ 1; i++)
    {
        count[i]+= count[i- 1];
    }
    int* temp= new int[n];
    for(int i= 0; i< n; i++)
    {
        temp[count[v[i]]- 1]= v[i];
        count[v[i]]--;
    }
    for(int i= 0; i< n; i++)
    {
        v[i]= temp[i];
    }
}
void countSortneg(int v[], int n)
{
    //count sort for negative numbers too
    int min= v[0];
    int max= v[0];
    for(int i= 1; i< n; i++)
    {
        if(v[i]< min)
        {
            min= v[i];
        }
        if(v[i]> max)
        {
            max= v[i];
        }
    }
    int range= max- min+ 1;
    int* count= new int[range];
    for(int i= 0; i< range; i++)
    {
        count[i]= 0;
    }
    for(int i= 0; i< n; i++)
    {
        count[v[i]- min]++;
    }
    for(int i= 1; i< range; i++)
    {
        count[i]+= count[i- 1];
    }
    int* temp= new int[n];
    for(int i= 0; i< n; i++)
    {
        temp[count[v[i]- min]- 1]= v[i];
        count[v[i]- min]--;
    }
    for(int i= 0; i< n; i++)
    {
        v[i]= temp[i];
    }
}
void countSortRadix(int v[], int n, int place)
{
    // count sort for radix sort
    const int max= 10;
    int* count= new int[max];
    for(int i= 0; i< max; i++)
    {
        count[i]= 0;
    }
    for(int i= 0; i< n; i++)
    {
        count[(v[i]/ place)% 10]++;
    }
    for(int i= 1; i< max; i++)
    {
        count[i]+= count[i- 1];
    }
    int* temp= new int[n];
    for(int i= n-1; i>= 0; i--)
    {
        temp[count[(v[i]/ place)% 10]- 1]= v[i];
        count[(v[i]/ place)% 10]--;
    }
    for(int i= 0; i< n; i++)
    {
        v[i]= temp[i];
    }
    delete []count;
    delete []temp;
}
int getMax(int v[], int n)
{
    //get max element
    int max= v[0];
    for(int i= 1; i< n; i++)
    {
        if(v[i]> max)
        {
            max= v[i];
        }
    }
    return max;
}
void radixSort(int v[], int n)
{
    //radix sort
    // int max= v[0];
    // for(int i= 1; i< n; i++)
    // {
    //     if(v[i]> max)
    //     {
    //         max= v[i];
    //     }
    // }
    int max= getMax(v, n);
    for(int i= 1; max/i> 0; i*= 10)
    {
        countSortRadix(v, n, i);
    }
}
int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}
int main()
{
    cout<<"Enter size of array"<<endl;
    int n;
    cin >> n;
    int* v= new int[n];
    takeInput(v, n);
    // insertionSort(v, n);
    // quickSort(v, n);
    // mergeSort(v, n);
    // selectionSort(v, n);
    // countSort(v, n);
    // countSortneg(v, n);
    radixSort(v, n);
    printVector(v, n);
    return 0;
}
