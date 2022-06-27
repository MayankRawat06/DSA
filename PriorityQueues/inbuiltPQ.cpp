#include <queue>
#include <iostream>
using namespace std;
typedef pair<int, pair<int, int>> triplet;
void kSortedArray(vector<int>& v, int n, int k) {
    priority_queue<int> pq;
    for(int i = 0; i < k; i++) {
        pq.push(v[i]);
    }
    int j = 0;
    for(int i = k; i < n; i++) {
        v[j] = pq.top();
        pq.pop();
        pq.push(v[i]);
        j++;
    }
    while(j < n) {
        v[j] = pq.top();
        pq.pop();
        j++;
    }
}
vector<int> kSmallestNo(vector<int>& v, int n, int k) {
    vector<int> res(k);
    priority_queue<int> pq;
    for(int i = 0; i < k; i++) {            
        pq.push(v[i]);
    }
    for(int i = k; i < n; i++) {
        if(pq.top() > v[i]) {
            pq.pop();
            pq.push(v[i]);
        }
    }
    int j = 0;
    while(!pq.empty()) {
        res[j] = pq.top();
        pq.pop();
        j++;
    }
    return res;
}
vector<int> kLargest(vector<int>& v, int n, int k) {
    priority_queue<int, vector<int>, greater<int> > pq;
    vector<int> res(k);
    for(int i = 0; i < n; i++) {
        if(i < k) {
            pq.push(v[i]);
        }
        else {
            if(pq.top() < v[i]) {
                pq.pop();
                pq.push(v[i]);
            }
        }
    }
    int j = 0;
    while(!pq.empty()) {
        res[j] = pq.top();
        pq.pop();
        j++;
    }
    return res;
}
bool checkMaxHeap(vector<int> v, int n) {
    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(n > 2 * i + 1) {
            if(v[i] >= v[2 * i + 1]) {
                if(n > 2 * i + 2) {
                    if (v[i] >= v[2 * i + 2]) {
                        flag = true;
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
            }
            else {
                flag = false;
                break;
            }
        }
    }
    return flag;
}
int kthLargest(vector<int> v, int n, int k) {
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < n; i++) {
        if(i < k) {
            pq.push(v[i]);
        }
        else {
            if(pq.top() < v[i]) {
                pq.pop();
                pq.push(v[i]);
            }
        }
    }
    return pq.top();
}
vector<int> mergeKsorted(vector<vector<int>> lists, int k) {
    vector<int> res;
    priority_queue<triplet, vector<triplet>, greater<triplet> > pq;
    for(int i = 0; i < k; i++) {
        pq.push({lists[i][0], {i, 0}});
    }
    while(!pq.empty()) {
        triplet x = pq.top();
        int ai = x.second.first;
        int ei = x.second.second;
        pq.pop();
        res.push_back(x.first);
        if(ei + 1 < lists[ai].size()) {
            pq.push({lists[ai][ei + 1], {ai, ei + 1}});
        }
    }
    return res;
}
int signum(int a, int b) {
    if(a == b) {
        return 0;
    }
    return a > b ? 1 : -1;
}
int average(int a, int b) {
    return 0.5 * (a + b);
}
int runningMedians(int e, int& m, priority_queue<int>& l, priority_queue<int, vector<int>, greater<int> >& r) {
    int sig = signum(l.size(), r.size());
    switch(sig) {
        case 1 :
            if(e < m) {
                r.push(l.top());
                l.pop();
                l.push(e);
            }
            else {
                r.push(e);
            }
            m = average(l.top(), r.top());
            break;
        case -1 :
            if(e > m) {
                l.push(r.top());
                r.pop();
                r.push(e);
            }
            else {
                l.push(e);
            }
            m = average(l.top(), r.top());    
            break;
        case 0 :
            if(e < m) {
                l.push(e);
                m = l.top();
            }
            else {
                r.push(e);
                m = r.top();
            }
            break;
    }
    return m;

}
void runningMedians(vector<int> v, int n) {
    int m = 0;
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int> > r;
    for(int i = 0; i < n; i++) {
        int m = runningMedians(v[i], m, l, r);
        cout << m << endl;
    }
}
int buyTickets(vector<int> v, int n, int index) {
    queue<int> q;
    priority_queue<int> pq;
    int t = 0;
    for(int i = 0; i < n; i++) {
        q.push(i);
        pq.push(v[i]);
    }
    while(!pq.empty()) {
        if(pq.top() == v[q.front()]) {
            t++;
            if(q.front() == index) {
                break;
            }
            pq.pop();
            q.pop();
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }
    return t;
}
int main() {
    // priority_queue<int> pq;
    // pq.push(63);
    // pq.push(172);
    // pq.push(2);
    // pq.push(87);
    // pq.push(35);
    // pq.push(93);
    // pq.push(1);
    // cout << pq.empty() << endl;
    // cout << pq.size() << endl;
    // cout << pq.top() << endl;
    // while(!pq.empty()) {
    //     cout << pq.top() << endl;
    //     pq.pop();
    // }
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // runningMedians(v, n);
    int index;
    cin >> index;
    cout << buyTickets(v, n, index) << endl;
    // cout << checkMaxHeap(v, n) << endl;
    // int k;
    // cin >> k;
    
    // kSortedArray(v, n, k);
    // for(auto i : v) {
    //     cout << i << " ";
    // }
    // cout << kthLargest(v, n, k) << endl;
    // vector<int> res1 = kSmallestNo(v, n, k);
    // vector<int> res2 = kLargest(v, n, k);
    // for(auto i : res1) {
    //     cout << i << " ";
    // }
    // for(auto i : res2) {
    //     cout << i << " ";
    // }
    // int k;
    // cin >> k;
    // int d = k;
    // vector<vector<int>> v;
    // while(d--) {
    //     int n;
    //     cin >> n;
    //     vector<int> t(n);
    //     for(int i = 0; i < n; i++) {
    //         cin >> t[i];
    //     }
    //     v.push_back(t);
    // }
    // vector<int> res = mergeKsorted(v, k);
    // for(auto i : res) {
    //     cout << i << " ";
    // }
    return 0;
}