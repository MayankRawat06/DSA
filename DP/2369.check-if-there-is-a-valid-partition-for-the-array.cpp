class Solution {
    vector<int> dp;
    int n;
    bool f(int i, vector<int>& v) {
        if(i >= n) return true;
        if(dp[i] != -1) return dp[i];
        bool twoEqual = false, threeEqual = false, threeConsecutive = false;
        if(i + 1 < n && v[i] == v[i + 1]) twoEqual = f(i + 2, v);
        if(i + 2 < n && v[i] == v[i + 1] && v[i + 1] == v[i + 2]) threeEqual = f(i + 3, v);
        if(i + 2 < n && v[i] == v[i + 1] - 1 && v[i + 1] == v[i + 2] - 1) threeConsecutive = f(i + 3, v);
        return dp[i] = twoEqual || threeEqual || threeConsecutive;
    }
public:
    bool validPartition(vector<int>& v) {
        n = v.size();
        dp.resize(n, -1);
        return f(0, v);
    }
};