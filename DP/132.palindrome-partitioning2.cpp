class Solution {
    bool check(int i, int j, string& s) {
        int l = i, r = j;
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    int f(int i, string& s, vector<int>& dp) {
        int n = s.size();
        if(i + 1 >= n || check(i, n - 1, s)) return 0;
        if(dp[i] != -1) return dp[i];
        int mini = n - 1;
        for(int j = i; j < n; j++) {
            if(check(i, j, s)) {
                int curr = 1 + f(j + 1, s, dp);
                if(j == n - 1) curr -= 1;
                mini = min(mini, curr);
            }
        }
        return dp[i] = mini;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, dp);
    }
};