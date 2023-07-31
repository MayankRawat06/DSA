class Solution {
    int n1, n2;
    vector<vector<int>> dp;
    int f(int i, int j, string& s1, string& s2) {
        if(i >= n1 && j >= n2) return 0;
        if(i >= n1) {
            int sum = 0;
            while(j < n2) {
                sum += s2[j];
                j++;
            }
            return sum;
        } 
        if(j >= n2) {
            int sum = 0;
            while(i < n1) {
                sum += s1[i];
                i++;
            }
            return sum;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = f(i + 1, j + 1, s1, s2);
        else return dp[i][j] = min(s1[i] + f(i + 1, j, s1, s2), s2[j] + f(i, j + 1, s1, s2));
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        n1 = s1.size(), n2 = s2.size();
        dp.resize(n1, vector<int>(n2, -1));
        return f(0, 0, s1, s2);
    }
};