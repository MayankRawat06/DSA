class Solution {
    int n;
    vector<int> dp;
    int f(int i, string& c, vector<int>& t, int prevc, int prevt) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        if(c[i] == prevc) return dp[i] = min(prevt, t[i]) + f(i + 1, c, t, prevc, max(prevt, t[i]));
        else return dp[i] = f(i + 1, c, t, c[i], t[i]);
    }
public:
    int minCost(string c, vector<int>& t) {
        n = t.size();
        dp.resize(n, -1);
        return f(0, c, t, 'A', 0);
    }
};