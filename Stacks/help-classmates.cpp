//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> v, int n) 
    { 
        // Your code goes here
        stack<int> s;
        vector<int> res(n);
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && s.top() >= v[i]) s.pop();
            res[i] = s.empty() ? -1 : s.top();
            s.push(v[i]);
        }
        return res;
    } 
};