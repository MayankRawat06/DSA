class Solution {
    int x, n;
    vector<vector<long long>> dp;
    long long f(int index, int p, vector<int>& v) {
        if(index >= n) return 0;
        if(dp[index][p] != -1) return dp[index][p];
        long long pick = INT_MIN, notPick = INT_MIN;
        if(p == v[index] % 2) pick = v[index] + f(index + 1, p, v);
        else pick = v[index] - x + f(index + 1, v[index] % 2, v);
        notPick = f(index + 1, p, v);
        return dp[index][p] = max(pick, notPick);
    }
public:
    long long maxScore(vector<int>& v, int z) {
        x = z, n = v.size();
        dp.resize(n, vector<long long>(2, -1));
        return v[0] + f(1, v[0] % 2, v);
    }
};