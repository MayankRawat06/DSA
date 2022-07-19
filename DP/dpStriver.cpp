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
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // cout << maxSum2(v, 0) << endl;
    // cout << frogJump2(v) << endl;
    cout << maxSum4(v) << endl;
    return 0;
}