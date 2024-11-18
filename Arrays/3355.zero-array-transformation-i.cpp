class Solution {
public:
    bool isZeroArray(vector<int>& v, vector<vector<int>>& q) {
        int n = v.size();
        vector<int> freq(n + 1, 0);
        for(auto query : q) {
            freq[query[0]]++;
            freq[query[1] + 1]--;
        }
        int op = 0;
        for(int i = 0; i < n; i++) {
            op += freq[i];
            if(v[i] > op) return false;
        }
        return true;
    }
};

// sweeping line algorithm