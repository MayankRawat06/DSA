class Solution{
public:
    vector<int> leftSmaller(int n, int v[]){
        // code here
        stack<int> s;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && v[s.top()] >= v[i]) s.pop();
            s.empty() ? res.push_back(-1) : res.push_back(v[s.top()]);
            s.push(i);
        }
        return res;
    }
};