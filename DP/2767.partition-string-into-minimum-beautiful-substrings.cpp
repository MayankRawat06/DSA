class Solution {
    vector<int> dp;
    int n;
    int f(int index, string& v) {
        if(index >= n ) return 0;
        if(v[index] == '0') return 1e9;
        if(dp[index] != -1) return dp[index];
        int curr = 0, res = 1e9;
        
        for(int j = index; j < n; j++) {
            curr <<= 1;
            curr |= (v[j] - '0');
            float x = log(curr) / log(5);
            int z = 1e9;
            if(curr != 0 && x == floor(x)) z = f(j + 1, v);
            res = min(1 + z, res);
        }
        return dp[index] = res;
    }
public:
    int minimumBeautifulSubstrings(string s) {
        n = s.size();
        dp.resize(n, -1);
        int res = f(0, s);
        return res >= 1e9 ? -1 : res;
    }
};