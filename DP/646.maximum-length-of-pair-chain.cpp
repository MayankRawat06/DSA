class Solution {
    int n;
    vector<vector<int>> dp;
    int f(int i, int pre, vector<vector<int>>& v) {
        if(i >= n) return 0;
        if(pre != -1 && dp[i][pre] != -1) return dp[i][pre];
        int pick = 0, notPick = 0;
        if(pre == -1 || v[i][0] > v[pre][1]) pick = 1 + f(i + 1, i, v);
        notPick = f(i + 1, pre, v);
        int res = max(pick, notPick);
        if(pre != -1) dp[i][pre] = res;
        return res;
    }
public:
    int findLongestChain(vector<vector<int>>& v) {
        n = v.size();
        sort(v.begin(), v.end());
        dp.resize(n, vector<int>(n, -1));
        return f(0, -1, v);
    }
};