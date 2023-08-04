class Solution {
    int m, n;
    vector<vector<int>> dp;
    int f(int i, int j, string& s, string& t) {
        if(j >= n) return 1;
        if(i >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int pick = 0, notPick = 0;
        if(s[i] == t[j]) pick = f(i + 1, j + 1, s, t);
        notPick = f(i + 1, j, s, t);
        return dp[i][j] = pick + notPick;
    }
public:
    int numDistinct(string s, string t) {
        m = s.size(), n = t.size();
        dp.resize(m, vector<int>(n, -1));
        return f(0, 0, s, t);
    }
};