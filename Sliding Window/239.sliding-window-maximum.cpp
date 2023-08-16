class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        int n = v.size();
        deque<int> q;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            while(!q.empty() && q.front() <= i - k) q.pop_front();
            while(!q.empty() && v[q.back()] <= v[i]) q.pop_back();
            q.push_back(i);
            if(i >= k - 1) res.push_back(v[q.front()]);
        }
        return res;
    }
};