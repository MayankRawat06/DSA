class Solution {
    int n;
    vector<vector<vector<int>>> dp;
    int f(int i, int k, bool isBuy, vector<int>& v) {
        if(k < 0) return -1e9;
        if(i >= n) return 0;
        if(dp[i][isBuy][k] != -1) return dp[i][isBuy][k];
        int pick = 0, notPick = 0;
        if(isBuy) {
            pick = -v[i] + f(i + 1, k - 1, false, v);
            notPick = f(i + 1, k, isBuy, v);
        }
        else {
            pick = v[i] + f(i + 1, k - 1, true, v);
            notPick = f(i + 1, k, isBuy, v);
        }
        return dp[i][isBuy][k] = max(pick, notPick);
    }
public:
    int maxProfit(int k, vector<int>& v) {
        n = v.size();
        dp.resize(n, vector<vector<int>>(2, vector<int>(2 * k + 1, -1)));
        return f(0, 2*k, 1, v);
    }
};