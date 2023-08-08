class Solution {
    // assume we're starting from last -- that's pick the last baloon to be burst
    vector<vector<int>> dp;
    long long f(int i, int j, vector<int>& v) {
        // even a single balloon is a subproblem -- so the base case would be no valid subproblem -- no balloon left
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        long long maxi = INT_MIN;
        // any balloon can be the last balloon
        for(int index = i; index <= j; index++) {
            long long curr = v[i - 1] * v[index] * v[j + 1] + f(i, index - 1, v) + f(index + 1, j, v);
            maxi = max(curr, maxi);
        }
        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& v) {
        int n = v.size();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        v.insert(v.begin(), 1);
        v.push_back(1);
        return f(1, n, v);
    }
};