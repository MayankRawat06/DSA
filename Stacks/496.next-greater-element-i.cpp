class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& v, vector<int>& a) {
        int m = v.size(), n = a.size();
        vector<int> res(m);
        stack<int> s;
        unordered_map<int, int> map;
        vector<int> nge(n, -1);
        for(int i = n - 1; i >= 0; i--) {
            map[a[i]] = i;
            while(!s.empty() && s.top() < a[i]) s.pop();
            if(s.empty()) nge[i] = -1;
            else nge[i] = s.top();
            s.push(a[i]);
        }
        for(int i = 0; i < m; i++) {
            int index = map[v[i]];
            res[i] = nge[index];
        }
        return res;
    }
};