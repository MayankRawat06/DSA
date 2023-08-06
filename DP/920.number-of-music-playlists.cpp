class Solution {
    int g, n, k, mod;
    vector<vector<int>> dp;
    long f(int count, int unique) {
        if(count == g) return unique == n;
        if(dp[count][unique] != -1) return dp[count][unique];
        long res = 0;
        if(n > unique)
            res += ((n - unique) * f(count + 1, unique + 1)) % mod; // play unique song
        res %= mod;
        if(unique > k)
            res += ((unique - k) * f(count + 1, unique)) % mod; // replay 
        return dp[count][unique] = res % mod;
    }
public:
    int numMusicPlaylists(int N, int goal, int K) {
        g = goal, k = K, n = N, mod = 1e9 + 7;
        dp.resize(goal + 1, vector<int>(n + 1, -1));
        return f(0, 0);
    }
};