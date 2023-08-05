class Solution {
    vector<int> dp;
    int f(int n) {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        int count = 0;
        for(int i = 1; i <= n; i++) {
            int curr = f(i - 1) * f(n - i);
            count += curr;
        }
        return dp[n] = count;
    }
public:
    int numTrees(int n) {
        dp.resize(n + 1, -1);
        return f(n);
    }
};