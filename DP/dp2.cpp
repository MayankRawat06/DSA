#include <iostream>
using namespace std;
int minCostHelper(int** v, int m, int n, int i, int j) {
    // base case
    if(i == m - 1 && j == n - 1) {
        return v[i][j];
    }
    if(i >= m || j >= n) {
        return INT16_MAX;
    }
    // recursive calls
    int x = minCostHelper(v, m, n, i, j + 1);
    int y = minCostHelper(v, m, n, i + 1, j + 1);
    int z = minCostHelper(v, m, n, i + 1, j);
    // small calculation
    return min(min(x, y), z) + v[i][j];
}
int minCost(int** v, int m, int n) {
    return minCostHelper(v, m, n, 0, 0);
}
int minCost2Helper(int** ip, int** op, int m, int n, int i, int j) {
    // base case
    if(i == m - 1 && j == n - 1) {
        return ip[i][j];
    }
    if(i >= m || j >= n) {
        return INT16_MAX;
    }
    // check if cost from p to end exist
    if(op[i][j] != -1) {
        return op[i][j];
    }
    else {
        // recursive calls
        int x = minCost2Helper(ip, op, m, n, i, j + 1);
        int y = minCost2Helper(ip, op, m, n, i + 1, j + 1);
        int z = minCost2Helper(ip, op, m, n, i + 1, j);
        // small calculation and saving the ans
        op[i][j] = min(min(x, y), z) + ip[i][j];
    }
    return op[i][j];
}
int minCost2(int** ip, int m, int n) {
    // memoization
    int** op = new int*[m];
    for(int i = 0; i < m; i++) {
        op[i] = new int[n];
        for(int j = 0; j < n; j++) {
            op[i][j] = -1;
        }
    }
    return minCost2Helper(ip, op, m, n, 0, 0);
}
int minCost3(int** ip, int m, int n) {
    int** op = new int*[m];
    for(int i = 0; i < m; i++) {
        op[i] = new int[n];
    }
    op[m - 1][n - 1] = ip[m - 1][n - 1];
    // fill the last row right to left
    for(int j = n - 2; j >= 0; j--) {
        op[m - 1][j] = op[m - 1][j + 1] + ip[m - 1][j];
    }
    // fill the last col bottom to top
    for(int i = m - 2; i >= 0; i--) {
        op[i][n - 1] = op[i + 1][n - 1] + ip[i][n - 1];
    }
    // fill the other cells right to left bottom to top
    for(int i = m - 2; i >= 0; i--) {
        for(int j = n - 2; j >= 0; j--) {
            op[i][j] = min(op[i][j + 1], min(op[i + 1][j + 1], op[i + 1][j])) + ip[i][j];
        }
    }
    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << op[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return op[0][0];
}
int lcs(string s, string t) {
    // base case
    if(s.size() == 0 || t.size() == 0) {
        return 0;
    }
    // recursive case 
    if(s[0] == t[0]) {
        return 1 + lcs(s.substr(1), t.substr(1));
    }
    else {
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        // not necessary, included while calculating a and b
        // int c = lcs(s.substr(1), t.substr(1));
        // return max(a, max(b, c));
        return max(a, b);
    }
}
int lcsHelper(string s, string t, int** dp) {
    int m = s.size();
    int n = t.size();
    if(s.size() == 0 || t.size() == 0) {
        return 0;
    }
    if(dp[m][n] != -1) {
        return dp[m][n];
    }
    else {
            if(s[0] == t[0]) {
            dp[m][n] = 1 + lcsHelper(s.substr(1), t.substr(1), dp);
        }
        else {
            int a = lcsHelper(s.substr(1), t, dp);
            int b = lcsHelper(s, t.substr(1), dp);
            dp[m][n] = max(a, b);
        }
        return dp[m][n];
    }
}
int lcs1(string s, string t) {
    // memoization
    int m, n;
    m = s.size();
    n = t.size();
    int** dp = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        dp[i] = new int[n + 1];
        for(int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }
    return lcsHelper(s, t, dp);
}
int lcs2(string s, string t) {
    // tabulation
    int m = s.size();
    int n = t.size();
    if(m == 0 || n == 0) {
        return 0;
    }
    int** dp = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        dp[i] = new int[n + 1];
    }
    dp[0][0] = 0;
    // filling first row with all 0s
    for(int j = 1; j <= n; j++) {
        dp[0][j] = 0;
    }
    // filling first col with all 0s
    for(int i = 1; i <= m; i++) {
        dp[i][0] = 0;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            // most imp part
            if(s[m - i] == t[n - j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int editDistance(string s, string t) {
    if(s.size() == 0 || t.size() == 0) {
        return max(s.size(), t.size());
    }
    // if(s.size() == 0) {
    //     return t.size();
    // }
    // else {
    //     return s.size();
    // }
    int ans;
    if(s[0] == t[0]) {
        ans = editDistance(s.substr(1), t.substr(1));
    }
    else {
        // insert into t
        int a = 1 + editDistance(s.substr(1), t);
        // remove from t
        int b = 1 + editDistance(s, t.substr(1));
        // replace
        int c = 1 + editDistance(s.substr(1), t.substr(1));
        ans = min(min(a, b), c);
    }
    return ans;
}
int editDistanceHelper(string s, string t, int** dp) {
    int m = s.size();
    int n = t.size();
    if(s.size() == 0 || t.size() == 0) {
        return max(s.size(), t.size());
    }
    if(dp[m][n] != -1) {
        return dp[m][n];
    }
    else {
        if(s[0] == t[0]) {
            dp[m][n] = editDistanceHelper(s.substr(1), t.substr(1), dp);
        }
        else {
            // insert
            int a = editDistanceHelper(s.substr(1), t, dp) + 1;
            // remove
            int b = editDistanceHelper(s, t.substr(1), dp) + 1;
            // replace
            int c = editDistanceHelper(s.substr(1), t.substr(1), dp) + 1;
            dp[m][n] = min(min(a, b), c);
        }
        return dp[m][n];
    }
}
int editDistance1(string s, string t) {
    int m, n;
    m = s.size();
    n = t.size();
    int** dp = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        dp[i] = new int[n + 1];
        for(int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }
    return editDistanceHelper(s, t, dp);
}
int editDistance2(string s, string t) {
    // tabulation
    int m = s.size();
    int n = t.size();
    if(s.size() == 0 || t.size() == 0) {
        return max(s.size(), t.size());
    }
    int **dp = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        dp[i] = new int[n + 1];
    };
    dp[0][0] = 0;
    // filling 0th row
    for(int j = 1; j <= n; j++) {
        dp[0][j] = j;
    }
    // filling 0th col
    for(int i = 1; i <= m; i++) {
        dp[i][0] = i;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[m - i] == t[n - j]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    return dp[m][n];
}
int knapsack(int w, int n, int* pi, int* wi) {
    if(n == 0 || w == 0) {
        return 0;
    }
    int a = INT16_MIN;
    if(wi[0] <= w) {
        a = pi[0] + knapsack(w - wi[0], n - 1, pi + 1, wi + 1);
    }
    int b = knapsack(w, n - 1, pi + 1, wi + 1);
    return max(a, b);
}
int knapsackHelper(int w, int n, int* pi, int* wi, int** dp) {
    if(n == 0 || w == 0) {
        return 0;
    }
    if(dp[n][w] != -1) {
        return dp[n][w];
    }
    else {
        int a = INT16_MIN;
        if(wi[0] <= w) {
            a = pi[0] + knapsack(w - wi[0], n - 1, pi + 1, wi + 1);
        }
        int b = knapsack(w, n - 1, pi + 1, wi + 1);
        dp[n][w] = max(a, b);
        return dp[n][w];
    }
}
int knapsack1(int w, int n, int* pi, int* wi) {
    // memoization
    int** dp = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[w + 1];
        for(int j = 0; j <= w; j++) {
            dp[i][j] = -1;
        }
    }
    return knapsackHelper(w, n, pi, wi, dp);
}
int knapsack2(int w, int n, int* pi, int* wi) {
    // tabulation
    int** dp = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[w + 1];
    }
    dp[0][0] = 0;
    for(int j = 1; j <= w; j++) {
        dp[0][j] = 0;
    }
    for(int i = 1; i <= n; i++) {
        dp[i][0] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= w; j++) {
            // comparing available capacity with weight of the obj
            if(j < wi[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(pi[i - 1] +  dp[i - 1][j - wi[i - 1]], dp[i - 1][j]);
            }
        }
    }
    return dp[n][w];
}

int main() {
    // int m , n;
    // cin >> m >> n;
    // int** input = new int*[m];
    // for(int i = 0; i < m; i++) {
    //     input[i] = new int[n];
    //     for(int j = 0; j < n; j++) {
    //         cin >> input[i][j];
    //     }
    // }
    // cout << minCost3(input, m , n) << endl;
    // string s, t;
    // cin >> s >> t;
    // cout << lcs2(s, t) << endl;
    // cout << editDistance2(s, t) << endl;
    int n, w;
    cin >> n;
    int* pi = new int[n];
    int* wi = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> wi[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> pi[i];
    }
    cin >> w;
    cout << knapsack2(w, n, pi, wi) << endl;
    return 0;
}