class Solution {
    int n;
    vector<int> dp;
    bool f(int index, string& s, vector<string>& v) {
        if(index >= n) return true;
        if(dp[index] != -1) return dp[index];
        bool res = false;
        for(string t : v) {
            if(s.substr(index, t.size()) == t) res = res || f(t.size() + index, s, v);
            if(res) return dp[index] = true;
        }
        return dp[index] = false;
    }
public:
    bool wordBreak(string s, vector<string>& words) {
        n = s.size();
        dp.resize(n, -1);
        return f(0, s, words);
    }
};