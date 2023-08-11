class Solution {
    int n;
    vector<vector<int>> dp;
    int f(int i, vector<int>& v, int k) {
        if(k == 0) return 1;
        if(k < 0 || i >= n) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int pick = 0, notPick = 0;
        pick = f(i, v, k - v[i]);
        notPick = f(i + 1, v, k);
        return dp[i][k] = pick + notPick;
    }
public:
    int change(int k, vector<int>& v) {
        n = v.size();
        dp.resize(n, vector<int>(k + 1, -1));
        return f(0, v, k);
    }
};