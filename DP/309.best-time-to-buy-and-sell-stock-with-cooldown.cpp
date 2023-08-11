class Solution {
    int n;
    vector<vector<int>> dp;
    int f(int i, bool isBuy, vector<int>& v) {
        if(i >= n) return 0;
        if(dp[i][isBuy] != -1) return dp[i][isBuy];
        int pick = 0, notPick = 0;
        if(isBuy) {
            pick = -v[i] + f(i + 1, false, v);
            notPick = f(i + 1, isBuy, v);
        }
        else {
            pick = v[i] + f(i + 2, true, v);
            notPick = f(i + 1, isBuy, v);
        }
        return dp[i][isBuy] = max(pick, notPick);
    }
public:
    int maxProfit(vector<int>& v) {
        n = v.size();
        dp.resize(n, vector<int>(2, -1));
        return f(0, 1, v);
    }
};