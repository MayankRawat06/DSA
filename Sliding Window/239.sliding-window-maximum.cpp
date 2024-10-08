class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        // monotonic stack
        // -- front - largest element but always the smaller index  
        // -- back - smallest element but could be largest index
        vector<int> res;
        deque<int> q; // indexes
        int n = v.size();
        for(int i = 0; i < n; i++) {
            // check out of bound from front 
            while(!q.empty() && q.front() <= i - k) q.pop_front();
            // remove any elements from queue that are smaller than current index element in array - from back
            while(!q.empty() && v[q.back()] <= v[i]) q.pop_back();
            q.push_back(i);
            if(i >= k - 1) res.push_back(v[q.front()]);
        }
        return res;
    }
};