class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();
        int res = 0;
        vector<int> nse(n), pse(n);
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && v[s.top()] >= v[i]) s.pop();
            pse[i] = s.empty() ? 0 : s.top() + 1;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && v[s.top()] >= v[i]) s.pop();
            nse[i] = s.empty() ? n - 1 : s.top() - 1;
            s.push(i);
        }
        for(int i = 0; i < n; i++) 
            res = max(res, (nse[i] - pse[i] + 1) * v[i]);
        return res;
    }
};