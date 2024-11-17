class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        stack<int> s;
        int n = v.size();
        vector<int> res(n);
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && v[s.top()] <= v[i]) s.pop();
            res[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }
        return res;
    }
};