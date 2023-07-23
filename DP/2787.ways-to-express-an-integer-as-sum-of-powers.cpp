class Solution {
    int x, mod = 1e9 + 7;
    
    long long f(int k, int n, vector<vector<int>>& dp) { 
        if(n == 0) return 1;
        if(k <= 0) return 0;
        if(dp[k][n] != -1) return dp[k][n];
        long long pick = 0, notPick = 0;
        int z = pow(k, x);
        if(n - z >= 0) pick = f(k - 1, n - z, dp) % mod;
        notPick = f(k - 1, n, dp) % mod;
        return dp[k][n] = (pick + notPick) % mod;
    }
public:
    int numberOfWays(int n, int p) {
        x = p;
        int i;
        for(i = 1; pow(i, x) <= n; i++);
        vector<vector<int>> dp(i + 1, vector<int>(n + 1, -1));
        return f(i, n, dp) % mod;
    }
};