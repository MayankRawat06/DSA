class Solution {
    vector<int> dx{-2,-2,2,2,-1,-1,1,1}, dy{-1,1,-1,1,-2,2,-2,2};
    int n;
    vector<vector<vector<double>>> dp;
    double f(int r, int c, int k) {
        if(r < 0 || r >= n || c < 0 || c >= n) return 0;
        if(k == 0) return 1;
        if(dp[r][c][k] != -1) return dp[r][c][k];
        double total = 0;
        for(int i = 0; i < 8; i++) total += f(r + dx[i], c + dy[i], k - 1);
        double p = total / 8.0;
        return dp[r][c][k] = p;
    }
public:
    double knightProbability(int sz, int k, int r, int c) {
        n = sz;
        dp.resize(n, vector<vector<double>>(n, vector<double>(k + 1, -1))); 
        return f(r, c, k);
    }
};