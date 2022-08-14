#include <iostream> 
#include <vector> 
#include <limits.h>
#include <math.h>
using namespace std;
int frogJumpHelper(vector<int>& v, int i) {
    if(i == 0) {
        return 0;
    }
    int left = frogJumpHelper(v, i - 1) + abs(v[i] - v[i - 1]);
    if(i > 1) {
        int right = frogJumpHelper(v, i - 2) + abs(v[i] - v[i - 2]);
        return min(left, right);
    }
    return left;
}
int frogJump(vector<int>& v) {
    int n = v.size();
    return frogJumpHelper(v, n - 1);
}
int frogJumpHelper1(vector<int>& v, int i, vector<int> dp) {
    if(i == 0) {
        return 0;
    }
    if(dp[i] != -1) {
        return dp[i];
    }
    int ans;
    int left = frogJumpHelper1(v, i - 1, dp) + abs(v[i] - v[i - 1]);
    if(i > 1) {
        int right = frogJumpHelper1(v, i - 2, dp) + abs(v[i] - v[i - 2]);
        ans = min(left, right);
    } 
    else 
    ans = left;
    return dp[i] = ans;
}
int frogJump1(vector<int>& v) {
    int n = v.size();
    vector<int> dp(n, -1);
    return frogJumpHelper1(v, n - 1, dp);
}
int frogJump2(vector<int>& v) {
    int n = v.size();
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = v[1];
    for(int i = 2; i < n; i++) {
        int left= dp[i - 1] + abs(v[i] - v[i - 1]);
        int right= dp[i - 2] + abs(v[i] - v[i - 2]);
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}
int frogJump3(vector<int>& v) {
    int n = v.size();
    vector<int> dp(n, -1);
    int prev2 = 0;
    int prev = v[1];
    int curr;
    for(int i = 2; i < n; i++) {
        int left= dp[i - 1] + abs(v[i] - v[i - 1]);
        int right= dp[i - 2] + abs(v[i] - v[i - 2]);
        curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int frogJumpx(vector<int>& v, int k) {
    int n = v.size();
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = v[1];
    int ans = INT_MAX;
    for(int i = 2; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            if(i - j >= 0) {
                int left= dp[i - j] + abs(v[i] - v[i - j]);
                ans = min(ans, left);
            }
            else {
                break;
            }
        }
        dp[i] = ans;
    }
    return dp[n - 1];
}
int maxSum(vector<int> v, int i) {
    // max sum of non adjacent element
    if(i < 0) {
        return 0;
    }
    int ans = 0;
    int pick = maxSum(v, i - 2) + v[i];
    int notPick = maxSum(v, i - 1);
    ans = max(pick, notPick);
    return ans;
}
int maxSum1(vector<int> v, int i) {
    // max sum of non adjacent element
    int n = v.size();
    if(i >= n) {
        return 0;
    }
    int ans = 0;
    int pick = maxSum1(v, i + 2) + v[i];
    int notPick = maxSum1(v, i + 1);
    ans = max(pick, notPick);
    return ans;
}
int maxSum2(vector<int> v, int i) {
    int n = v.size();
    vector<int> dp(n, -1);
    if(i >= n) {
        return 0;
    }
    if(dp[i] != -1) {
        return dp[i];
    }
    int ans = 0;
    int pick = maxSum1(v, i + 2) + v[i];
    int notPick = maxSum1(v, i + 1);
    ans = max(pick, notPick);
    return dp[i] = ans;
}
int maxSum3(vector<int> v) {
    int n = v.size();
    vector<int> dp(n, 0);
    dp[0] = v[0];
    for(int i = 1; i < n; i++) {
        if(i - 1 >= 0) {
            dp[i] = max(dp[i], dp[i - 1]);
        }
        if(i - 2 >= 0) {
            dp[i] = max(dp[i], dp[i - 2] + v[i]);
        }
    }
    return dp[n - 1];
}
int maxSum4(vector<int> v) {
    int n = v.size();
    int prev = v[0], prev2 = 0;
    int cur = 0;
    for(int i = 1; i < n; i++) {
        cur = 0;
        if(i - 1 >= 0) {
            cur = max(cur, prev);
        }
        if(i - 2 >= 0) {
            cur = max(cur, prev2 + v[i]);
        }
        prev2 = prev;
        prev = cur;
    }
    return prev;
}
int cutRodHelper(vector<int>& p, int i, int n, vector<vector<int>>& dp) {
    if(i == 0) return n * p[i];
    if(dp[i][n] != -1) return dp[i][n];
    int pick, notPick;
    pick = notPick = INT_MIN;
    notPick = f(p, i - 1, n, dp);
    if(n - (i + 1) >= 0) pick = p[i] + f(p, i, n - (i + 1), dp);
    return dp[i][n] = max(pick, notPick);
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return cutRodHelper(price, n - 1, n, dp);
}
int cutRod1(vector<int> &p, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for(int j = 0; j <= n; j++) 
        dp[0][j] = j * p[0];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= n; j++) {
            int pick, notPick;
            pick = notPick = INT_MIN;
            notPick = dp[i - 1][j];
            if(j - (i + 1) >= 0) pick = p[i] + dp[i][j - (i + 1)];
            dp[i][j] = max(pick, notPick);
        }
    }
    return dp[n - 1][n];
}
int cutRod2(vector<int> &p, int n)
{
    vector<int>prev (n + 1, 0);
    for(int j = 0; j <= n; j++) 
        prev[j] = j * p[0];
    for(int i = 1; i < n; i++) {
        vector<int>curr (n + 1, 0);
        for(int j = 0; j <= n; j++) {
            int pick, notPick;
            pick = notPick = INT_MIN;
            notPick = prev[j];
            if(j - (i + 1) >= 0) pick = p[i] + curr[j - (i + 1)];
            curr[j] = max(pick, notPick);
        }
        prev = curr;
    }
    return prev[n];
}
int cutRod3(vector<int> &p, int n)
{
    vector<int>prev (n + 1, 0);
    for(int j = 0; j <= n; j++) 
        prev[j] = j * p[0];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= n; j++) {
            int pick, notPick;
            pick = notPick = INT_MIN;
            notPick = prev[j];
            if(j - (i + 1) >= 0) pick = p[i] + prev[j - (i + 1)];
            prev[j] = max(pick, notPick);
        }
    }
    return prev[n];
}
int maxMerit(vector<vector<int>> v, int x, int d) {
    int n = v.size();
    // if(n <= 0) {
    //     return 0;
    // }
    if(d >= n) {
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        if(x!=i) {
            int pick = v[d][i] + maxMerit(v, i, d + 1);
            ans = max(ans, pick);
        }
    }
    return ans;
}
int maxMerit1(vector<vector<int>> v, int x, int d) {
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    if(d >= n) {
        return 0;
    }
    if(dp[d][x]!= -1) {
        return dp[d][x];
    }
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        if(x != i) {
            int pick = v[d][i] + maxMerit1(v, i, d + 1);
            ans = max(ans, pick);
        }
    }
    return dp[d][x] = ans;
}
int maxMerit2(vector<vector<int>> v, int x, int d) {
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    dp[0][0] = max(v[0][1], v[0][2]);
    dp[0][1] = max(v[0][0], v[0][2]);
    dp[0][2] = max(v[0][0], v[0][1]);
    dp[0][3] = max(max(v[0][0], v[0][1]), v[0][2]);
    for(int i = 1; i < n; i++) {
        int temp =0;
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 3; k++) {
                if(k != j) {
                    temp =  max(v[i][k] + dp[i - 1][k], temp);
                }
            }
            dp[i][j] = temp;
        }
    }
    return dp[n - 1][3];
}
int maxMerit3(vector<vector<int>> v, int x, int d) {
    int n = v.size();
    vector<int> dp(4, 0);
    dp[0] = max(v[0][1], v[0][2]);
    dp[1] = max(v[0][0], v[0][2]);
    dp[2] = max(v[0][0], v[0][1]);
    dp[3] = max(max(v[0][0], v[0][1]), v[0][2]);
    for(int i = 1; i < n; i++) {
        int temp =0;
        vector<int> t(4, 0);
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 3; k++) {
                if(k != j) {
                    temp =  max(v[i][k] + dp[k], temp);
                }
            }
            t[j] = temp;
        }
        dp = t;
    }
    return dp[3];
}
int minimumDifference(vector<int>& v) {
    int n = v.size();
    int t = accumulate(v.begin(), v.end(), 0);
    vector<vector<bool>> dp(n, vector<bool>(t + 1, false));
    for(int i = 0; i < n; i++) {
        dp[i][0] =true;
    }
    if(v[0] <= t && v[0] >= 0)  dp[0][v[0]] = true;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= t; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j - v[i] >= 0)   dp[i][j] = dp[i][j] || dp[i][j - v[i]];
        }
    }
    int mini = 1e9;
    for(int i = 0; i <= t; i++) {
        if(dp[n - 1][i] == true) {
            int s1 = i;
            int s2 = t - s1;
            mini = min(abs(s1 - s2), mini);
        }
    }
    return mini;        
}
int countSubsets(vector<int>& v, int i, int s) {
    if(s < 0) {
        return 0;
    }
    if(s == 0 && i >= 0) {
        return 1;
    }
    if(i == 0) {
        return v[i] == s;
    }
    int pick = 0, notPick = 0;
    if(v[i] <= s)    pick = countSubsets(v, i - 1, s - v[i]);
    notPick = countSubsets(v, i - 1, s);
    return pick + notPick;
}
int fcs(vector<int>& v, int i, int j, vector<vector<int>>& dp) {
    if(j < 0) {
        return 0;
    }
    if(j == 0 && i >= 0) {
        return 1;
    }
    if(i == 0) {
        return v[i] == j;
    }
    if(dp[i][j] != -1) return dp[i][j];
    int pick = 0, notPick = 0;
    if(v[i] <= j)    pick = fcs(v, i - 1, j - v[i], dp);
    notPick = fcs(v, i - 1, j, dp);
    return dp[i][j] = pick + notPick;
}
int countSubsets1(vector<int>& v, int s) {
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(s + 1, -1));
    return fcs(v, s, n - 1, dp);
}
int countSubsets2(vector<int>& v, int s) {
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(s + 1, 0));
    for(int i = 0; i < n; i++) {
       dp[i][0] = 1;
    }
    if(v[0] <= s) dp[0][v[0]] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= s; j++) {
            int pick = 0, notPick = 0;
            if(v[i] <= j)    pick = dp[i - 1][j - v[i]];
            notPick = dp[i - 1][j];
            dp[i][j] = pick + notPick;
        }
    }
    return dp[n - 1][s];
}
int countSubsets3(vector<int>& v, int s) {
    int n = v.size();
    vector<int> prev(s + 1, 0);
    prev[0] = 1;
    if(v[0] <= s) prev[v[0]] = 1;
    for(int i = 1; i < n; i++) {
        vector<int> curr(s + 1, 0);
        curr[0] = 1;
        for(int j = 1; j <= s; j++) {
            int pick = 0, notPick = 0;
            if(v[i] <= j)    pick = prev[j - v[i]];
            notPick = prev[j];
            curr[j] = pick + notPick;
        }
        prev = curr;
    }
    return prev[s];
}
