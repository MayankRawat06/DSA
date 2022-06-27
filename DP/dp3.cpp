#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
using namespace std;
int lootHouses(int n, vector<int> v) {
    if(n <= 0) {
        return 0;
    }
    if(n == 1) {
        return v[0];
    }
    int inc = v[n - 1] + lootHouses(n - 2, v);
    int notInc = lootHouses(n - 1, v);
    return max(inc, notInc);
}
int lootHousesHelper(int n, vector<int> v, vector<int>& dp) {
    if(n <= 0) {
        return 0;
    }
    if(n == 1) {
        return v[0];
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    else {
        int inc = v[n - 1] + lootHousesHelper(n - 2, v, dp);
        int notInc = lootHousesHelper(n - 1, v, dp);
        dp[n] = max(inc, notInc);
    }
    return dp[n];
}
int lootHouses1(int n, vector<int> v) {
    vector<int> dp(n + 1, -1);
    return lootHousesHelper(n, v, dp);
}
int lootHouses2(int n, vector<int> v) {
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = v[0];
    for(int i = 2; i <= n; i++) {
        int inc = v[i - 1] + dp[i - 2];
        int notInc = dp[i - 1];
        dp[i] = max(inc, notInc);
    }
    return dp[n];
}
int lis(int n, vector<int> v) {
    int *dp = new int[n];
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        dp[i] = 1;
        int j = i - 1;
        int maxm = 1;
        while(j >= 0) {
            int temp = 0;
            if(v[i] > v[j]) {
                temp = dp[j] + 1;
            }
            maxm = max(temp, maxm);
            j--;
        }
        dp[i] = maxm;
    }
    int best = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i] > best) {
            best = dp[i];
        }
    }
    delete []dp;
    return best;
}
int allPossibleWaysHelper(int num, int x, int k, int y) {
    int res = 0;
    if(x == 0) {
        res++;
    }
    int r = (int)floor(pow(num, 1.0/y));
    for(int i = k + 1; i <= r; i++) {
        int a = x - (int)pow(i, y); 
        if(a >= 0) {
            res+= allPossibleWaysHelper(num, a, i, y);
        }
    }
    return res;
}
int allPossibleWays(int x, int y) {
    return allPossibleWaysHelper(x, x, 0, y);
}
int allPWaysHelper(int remainingSum, int y, int b) {
    int res = pow(b, y);
    if(res == remainingSum) {
        return 1;
    }
    if(res > remainingSum) {
        return 0;
    }
    int u = allPWaysHelper(remainingSum - res, y, b + 1);
    int v = allPWaysHelper(remainingSum, y, b + 1);
    return u + v;
}
int allPWays(int x, int y) {
    return allPWaysHelper(x, y, 1);
}
int coinChangeAllWays(int n, vector<int> v, int num) {
    if(num < 0) {
        return 0;
    }
    if(num == 0) {
        return 1;
    }
    if(n <= 0 && num > 0) {
        return 0;
    }
    int total = 0;
    int a = coinChangeAllWays(n, v, num - v[n - 1]);
    int b = coinChangeAllWays(n - 1, v, num);
    total = (a + b);
    return total;
}
int coinChange1(int n, vector<int> v, int num){
    int **dp = new int*[n];
    for(int i = 0; i < n; i++) {
        dp[i] = new int[num + 1];
    }
    for(int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= num; j++) {
            if(j < v[i]) {
                if(i == 0) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            else {
                if(i < 1) {
                    if(j%v[i] == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - v[i]];
                }
            }
        }
    }
    int ans = dp[n - 1][num];
    for(int i = 0; i < n; i++) {
        delete[] dp[i];
    }
    delete []dp;
    return ans;
}
int minCoins(int n, vector<int> v, int amt) {
    if(amt == 0) {
        return 0;
    }
    int res = INT16_MAX;
    for(int i = 0; i < n; i++) {
        if(v[i] <= amt) {
            int subres = minCoins(n, v, amt - v[i]);
            if(subres != INT16_MAX && subres + 1 < res) {
                res = subres + 1;
            }
        }
    }
    return res;
}
int minCoins1(int n, vector<int> v, int amt) {
    sort(v.begin(), v.end());
    vector<vector<int>> dp(n, vector<int>(amt + 1, 0));
    // 0th col all 0s
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= amt; j++) {
            if(v[i] > j) {
                if(i < 1) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            else {
                if(i < 1) {
                    if(j % v[i] == 0) {
                        dp[i][j] = j / v[i];
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
                else {
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - v[i]]);
                }
            }
        }
    }
    // if(dp[n - 1][amt] == 0 && amt != 0) {
    //     return -1;
    // }

    return dp[n - 1][amt];
}
int minCoins2(int n, vector<int> v, int amt)  {
    vector<int> dp(amt + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= amt; i++) {
        for(int j = 0; j < n; j++) {
            if(v[j] <= i) {
                int subres = dp[i - v[j]];
                if(subres != INT_MAX && 1 + subres < dp[i]) {
                    dp[i] = 1 + subres;
                }
            }
        }
    }
    if(dp[amt] == INT_MAX) {
        return -1;
    }
    return dp[amt];
}
int mcm(int n, vector<int> v) {
    vector<vector<int>> m(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(abs(i - j) == 1) {
                m[i][j] = v[i] * v[i + 1] * v[j + 1];
            }
            if(i == j) {
                m[i][j] = 0;
            }
            
        }
    }
}
int main() {
    // int n;
    // cin >> n;
    // vector<int> v(n);
    // for(int i = 0; i < n; i++) {
    //     cin >> v[i];
    // }
    // cout << lis(n, v) << endl;
    // int x, y;
    // cin >> x >> y;
    // cout << allPossibleWays(x, y) << endl;
    // cout << allPWays(x, y) << endl;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int num;
    cin >> num;
    // cout << coinChange1(n, v, num) << endl;
    cout << minCoins2(n, v, num) << endl;
    return 0;
}