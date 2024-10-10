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




// Alternative and readable solution


class Solution {
    vector<int> fpse(vector<int>& v) {
        vector<int> res;
        stack<int> s;
        int n = v.size();
        for(int i = 0; i < n; i++) {
            while(!s.empty() && v[s.top()] >= v[i]) s.pop();
            s.empty() ? res.push_back(-1) : res.push_back(s.top());
            s.push(i);
        }
        return res;
    }
    vector<int> fnse(vector<int>& v) {
        stack<int> s;
        int n = v.size();
        vector<int> res(n);
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && v[s.top()] >= v[i]) s.pop();
            s.empty() ? res[i] = n : res[i] = s.top();
            s.push(i);
        }
        return res;
    }
public:
    int largestRectangleArea(vector<int>& v) {
        vector<int> pse = fpse(v);
        vector<int> nse = fnse(v);
        int maxi = 0, n = v.size();
        for(int i = 0; i < n; i++) {
            int h = v[i], w = nse[i] - pse[i] - 1;
            int area = h * w;
            maxi = max(maxi, area);
        }
        return maxi;
    }
};