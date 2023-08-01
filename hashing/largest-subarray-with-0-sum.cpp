/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&v, int n)
    {   
        // Your code here
        unordered_map<int, int> pre;
        int prefix = v[0];
        pre[prefix] = 0;
        int res = 0;
        if(prefix == 0) res = max(res, 1);
        
        for(int i = 1; i < n; i++) {
            prefix += v[i];
            if(prefix == 0) res = max(res, i + 1);
            else if(pre.find(prefix) != pre.end()) {
                res = max(res, i - pre[prefix]);
            }
            else pre[prefix] = i;
        }
        return res;
    }
};