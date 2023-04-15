class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size(), vector<int>(k + 1, -1));
        return f(0, piles, k, dp);
    }
    int f(int index, vector<vector<int>>& piles, int k, vector<vector<int>>& dp) {
        if(index >= piles.size()) return 0;
        if(k == 0) return 0;
        if(dp[index][k] != -1) return dp[index][k];
        int notPick = f(index + 1, piles, k, dp);
        int sum = 0;
        int pick = INT_MIN;
        for(int i = 0; i < piles[index].size(); i++) {
            if(i + 1 <= k) {
                sum += piles[index][i];
                pick = max(pick, sum + f(index + 1, piles, k - i - 1, dp));
            }
            else break;
        }
        return dp[index][k] = max(pick, notPick);
    }
};