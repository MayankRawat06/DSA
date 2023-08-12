class Solution {
    int m, n;
    vector<vector<int>> dp;
    int f(int i, int j, vector<vector<int>>& v) {
        if(i >= m || j >= n || v[i][j] == 1) return 0;
        if(i == m - 1 && j == n - 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = f(i + 1, j, v) + f(i, j + 1, v);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        m = v.size(), n = v[0].size();
        dp.resize(m, vector<int>(n, -1));
        return f(0, 0, v);
    }
};