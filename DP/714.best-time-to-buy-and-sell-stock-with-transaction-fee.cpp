class Solution {
    int n, fee;
    vector<vector<int>> dp;
    int f(int i, bool isBuy, vector<int>& v) {
        if(i >= n) return isBuy ? 0 : -1e9;
        if(dp[i][isBuy] != -1) return dp[i][isBuy];
        int pick = 0, notPick = 0;
        if(isBuy) {
            pick = -v[i] + f(i + 1, false, v);
            notPick = f(i + 1, isBuy, v);
        }
        else {
            pick = v[i] - fee + f(i + 1, true, v);
            notPick = f(i + 1, isBuy, v);
        }
        return dp[i][isBuy] =  max(pick, notPick);
    }
public:
    int maxProfit(vector<int>& v, int fee) {
        this -> fee = fee;
        n = v.size();
        dp.resize(n, vector<int>(2, -1));
        return f(0, 1, v);
    }
};