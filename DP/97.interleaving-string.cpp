class Solution {
    int p, q, n;
    vector<vector<int>> dp;
    bool f(int i, int j, int k, string& a, string& b, string& s) {
        if(k >= n) return true;
        if(i >= p) {
            for(int x = k; x < n; x++) {
                if(s[x] != b[j++]) return false;
            }
            return true;
        }
        if(j >= q) {
            for(int x = k; x < n; x++) {
                if(s[x] != a[i++]) return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[k] == a[i] && s[k] == b[j]) return dp[i][j] = f(i + 1, j, k + 1, a, b, s) || f(i, j + 1, k + 1, a, b, s);
        else if(s[k] == a[i]) return dp[i][j] = f(i + 1, j, k + 1, a, b, s);
        else if(s[k] == b[j]) return dp[i][j] = f(i, j + 1, k + 1, a, b, s);
        return dp[i][j] = false;
    }
    
public:
    bool isInterleave(string a, string b, string s) {
        p = a.size(), q = b.size(), n = s.size();
        if(p + q != n) return false;
        dp.resize(p, vector<int>(q, -1));
        return f(0, 0, 0, a, b, s);
    }
};