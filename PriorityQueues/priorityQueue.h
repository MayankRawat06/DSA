#include <iostream>
#include <vector>
using namespace std;
class PriorityQueue {
    // min-heap
    vector<int> pq;
    public :
    PriorityQueue() {

    }
    bool isEmpty() {
        return pq.size() == 0;
    }
    int getSize() {
        return pq.size();
    }
    int getMin() {
        if(isEmpty()) {
            return 0; // Priority Queue is empty
        }
        return pq[0];
    }
    void insert(int x) {
        pq.push_back(x);
        // up heapify
        int i = pq.size() - 1;
        while(i > 0 && pq[i] < pq[(i - 1) / 2]) {
            swap(pq[i], pq[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    int deleteMin() {
        if(isEmpty()) {
            return 0; // Priority Queue is empty
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        // down heapify
        int i = 0;
        while(2 * i + 1 < pq.size()) {
            int minIndex = 2 * i + 1;
            if(2 * i + 2 < pq.size()){
                minIndex = (pq[2 * i + 1] < pq[2 * i + 2]) ? 2 * i + 1 : 2 * i + 2;
            }
            if(i == minIndex) {
                break; // parent is the min -- leaf node
            }
            if(pq[i] > pq[minIndex]) {
                swap(pq[i], pq[minIndex]);
                i = minIndex;
            } else {
                break;
            }
        }
        return ans;
    }
};