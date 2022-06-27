#include <iostream>
#include <vector>
using namespace std;
void inplaceHeapSort(int n, vector<int>& v) {
    // build the heap in input array 
    for(int i = 1; i < n; i++) {
        while(i > 0 && v[i] < v[(i - 1) / 2]) {
            swap(v[i], v[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    // remove elements
    int e = n;
    while(e > 1) {
        swap(v[0], v[e - 1]);
        e--;
        int i = 0;
        while(2 * i + 1 < e) {
            int minIndex = 2 * i + 1;
            if(2 * i + 2 < e) {
                minIndex = (v[2 * i + 1] < v[2 * i + 2]) ? 2 * i + 1 : 2 * i + 2;
            }
            if(i == minIndex) {
                break;
            }
            if(v[i] > v[minIndex]) {
                swap(v[i], v[minIndex]);
                i = minIndex;
            }
            else {
                break;
            }
        }
    }
    

}
int main() {
    int n;
    cout << "Enter the number of elements" << endl;
    cin >> n;
    vector<int>v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    inplaceHeapSort(n, v);
    for(auto i : v) {
        cout << i << " ";
    }
}