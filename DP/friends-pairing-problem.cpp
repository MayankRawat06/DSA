class Solution
{
    int mod = 1e9 + 7;
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<long long> dp(n + 1);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = (((i - 1) * dp[i - 2]) % mod + dp[i - 1]) % mod;
        }
        return dp[n] % mod;
    }
};    
 