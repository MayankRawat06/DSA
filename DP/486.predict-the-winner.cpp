class Solution {
    int n;
    vector<vector<int>> dp;
public:
    long long f(int s, int e, vector<int>& v) {
        if(s > e) return 0;
        if(dp[s][e] != -1) return dp[s][e];
        long long score = max(v[s] + min(f(s + 2, e, v), f(s + 1, e - 1, v)), v[e] + min(f(s + 1, e - 1, v), f(s, e - 2, v)));
        return dp[s][e] = score;
    }
    bool PredictTheWinner(vector<int>& v) {
        n = v.size();
        dp.resize(n, vector<int>(n, -1));
        long long sum = 0;
        for(int x : v) {
            sum += x;
        }
        long long p1 = f(0, n - 1, v), p2 = sum - p1;
        return p1 >= p2;    
    }
};