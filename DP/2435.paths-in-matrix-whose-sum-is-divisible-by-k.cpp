class Solution {
    int k, m, n, mod;
    vector<vector<vector<int>>> dp;
    int f(int i, int j, long long sum, vector<vector<int>>& v) {
        if(i >= m || j >= n) return 0;
        if(i == m - 1 && j == n - 1) return (sum + v[i][j]) % k == 0;
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        int down = 0, right = 0;
        down = f(i + 1, j, (sum + v[i][j]) % k, v) % mod;
        right = f(i, j + 1, (sum + v[i][j]) % k, v) % mod;
        return dp[i][j][sum] = (down + right) % mod;
    }
public:
    int numberOfPaths(vector<vector<int>>& v, int K) {
        k = K, m = v.size(), n = v[0].size(), mod = 1e9 + 7;
        dp.resize(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return f(0, 0, 0, v) % mod;
    }
};