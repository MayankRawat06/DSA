class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        int n = v.size();
        vector<int> nge(n);
        stack<int> s;
        for(int i = 2 * n - 1; i >= 0; i--) {
            while(!s.empty() && v[i % n] >= s.top()) s.pop();
            if(i < n) {
                if(s.empty()) nge[i] = -1;
                else nge[i] = s.top();
            }
            s.push(v[i % n]);
        }
        return nge;
    }
};