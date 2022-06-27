#include <iostream>
#include <math.h>
#define mod 1000000007
using namespace std;
int fibo(int n) {
    // brute force
    if(n <= 1) {
        return n;
    }
    else 
    return fibo(n-1) + fibo(n-2);
}
int fiboHelper(int n, int* a) {
    if(n <= 1) {
        return n;
    }
    else {
        if(a[n] != -1) {
            return a[n];
        }
        else {
            a[n] = fiboHelper(n-1, a) + fiboHelper(n-2, a);
        }
    }
    return a[n];
}
int fibo1(int n) {
    // recursive using memoization
    int* a = new int[n + 1];
    for(int i = 0; i < n + 1; i++) {
        a[i] = -1;
    }
    return fiboHelper(n, a);
}
int fibo2(int n) {
    // iterative using tabulation
    // if(n <= 1) {
    //     return n;
    // }
    int* a = new int[n + 1];
    a[0] = 0;
    a[1] = 1;
    for(int i = 2; i <= n; i++) {
        a[i] = a[i-1] + a[i-2];
    }
    return a[n];
}
int minStepsToOne(int n) {
    // brute force
    if(n == 1) {
        return 0;
    }
    else {
        int a = INT8_MAX, b = INT8_MAX, c = INT8_MAX;
        if(n % 3 == 0) {
            a = 1 + minStepsToOne(n / 3);
        }
        if(n % 2 == 0) {
            b = 1 + minStepsToOne(n / 2);
        }
        c = 1 + minStepsToOne(n - 1);
        return min(min(a, b), c);
    }
}
int minStepsHelper(int* a, int n) {
    if(n == 1) {
        return 0;
    }
    if(a[n] != -1) {
        return a[n];
    }
    else {
        int z = INT8_MAX, b = INT8_MAX, c = INT8_MAX;
        if(n % 3 == 0) {
            z = 1 + minStepsHelper(a, n / 3);
        }
        if(n % 2 == 0) {
            b = 1 + minStepsHelper(a, n / 2);
        }
        c = 1 + minStepsHelper(a, n -1);
        a[n] = min(min(z, b), c);
        return a[n];
    }
}
int minStepsToOne1(int n) {
    // recursive memoization
    int* a = new int[n + 1];
    for(int i = 0; i <= n; i++) {
        a[i] = -1;
    }
    return minStepsHelper(a, n);
}
int minStepsToOne2(int n) {
    // iterative tabulation
    int* v = new int[n + 1];
    v[0] = 0;
    v[1] = 0;
    v[2] = 1;
    v[3] = 1;
    for(int i = 4; i <= n; i++) {
        int a = INT8_MAX, b = INT8_MAX, c = INT8_MAX;
        if(i % 3 == 0) {
            a = 1 + v[i / 3];
        }
        if(i % 2 == 0) {
            b = 1 + v[i / 2];
        }
        c = 1 + v[i - 1];
        v[i] = min(min(a, b), c);
    }
    return v[n];
}
int staircase(int n) {
    // brute force
    if(n < 0) {
        return 0;
    }
    if(n == 1 || n == 0) {
        return 1;        
    }
    // else if(n == 2) {
    //     return 2;
    // }
    // else if(n == 3) {
    //     return 4;
    // }
    else {
        return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
    }
}
int staircaseHelper(int* v, int n) {
    if(n < 0) {
        return 0;
    }
    if(n == 0) {
        return 1;
    }
    if(v[n] != -1) {
        return v[n];
    }
    else {
        v[n] = staircaseHelper(v, n - 1) + staircaseHelper(v, n - 2) + staircaseHelper(v, n - 3);
        return v[n];
    }
}
int staircase1(int n) {
    // using memoization
    int* v = new int[n + 1];
    for(int i = 0; i <= n; i++) {
        v[i] = -1;
    }
    return staircaseHelper(v, n);
}
int staircase2(int n) {
    // iterative tabulation
    int* v = new int[n + 1];
    v[0] = 1;
    v[1] = 1;
    v[2] = 2;
    v[3] = 4;
    for(int i = 4; i <= n; i++) {
        v[i] = v[i - 1] + v[i - 2] + v[i - 3];
    }
    return v[n];
}
int minCount(int n) {
    int r = sqrt(n);
    if(r*r == n) {
        return 1;
    }
    if(n <= 3) {
        return n;
    }
    int res = n;
    for(int i = 1; i <= r; i++) {
        int temp = i * i;
        if(temp > n) {
            break;
        }
        else {
            res = min(res, 1 + minCount(n - temp));
        }
    }
    return res;
}
int minCountHelper(int* v, int n) {
    int r = sqrt(n);
    if(r * r == n) {
        return 1;
    }
    else if(n <= 3) {
        return n;
    }
    if(v[n] != -1) {
        return v[n];
    }
    else {
        int res = n;
        for(int i = 1; i <= r; i++) {
            int temp = i * i;
            if(temp > n) {
                break;
            }
            else {
                res = min(res, 1 + minCountHelper(v, n - temp));
            }
        }
        v[n] = res;
    }
    return v[n];
}
int minCount1(int n) {
    // memoization
    int* v = new int[n + 1];
    for(int i = 0; i <= n; i++) {
        v[i] = -1;
    }
    return minCountHelper(v, n);
}
int minCount2(int n) {
    // iterative tabulation
    if(n <= 3) {
        return n;
    }
    int* v = new int[n + 1];
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    v[3] = 3;
    for(int i = 4; i <= n; i++) {
        v[i] = i;
        for(int x = 1; x <= sqrt(i); x++) {
            int temp = x * x;
            if(temp > n) {
                break;
            }
            else {
                v[i] = min(v[i], 1 + v[i - temp]);
            }
        }
    }
    return v[n];
}
int countBalBT(int h) {
    // brute force
    if(h == 0 || h == 1) {
        return 1;
    }
    int a = countBalBT(h - 1);
    int b = countBalBT(h - 2);
    // h - 1 h - 1, h - 1 h - 2, h - 2 h - 1
    int temp1 = (int)(((long)(a) * a) % mod);
    int temp2 = (int)((2 * (long)(a) * b) % mod);
    return (temp1 + temp2) % mod;
    // return ((2 * a * b) % mod + (a * a) % mod) % mod;
}
int countBTHelper(int* dp, int h) {
    if(h == 0 || h == 1) {
        return 1;
    }
    if(dp[h] != -1) {
        return dp[h];
    }
    else 
    {
        int a = countBalBT(h - 1);
        int b = countBalBT(h - 2);
        int temp1 = (int)(((long)(a) * a) % mod);
        int temp2 = (int)((2 * (long)(a) * b) % mod);
        dp[h] = (temp1 + temp2) % mod;
        // dp[h] = ((2 * a * b) % mod + (a * a) % mod) % mod;
        return dp[h];
    }
}
int countBalBT1(int h) {
    // memoization
    int* dp = new int[h + 1];
    for(int i = 0; i <= h; i++) {
        dp[i] = -1;
    }
    return countBTHelper(dp, h);
}
int countBalBT2(int h) {
    // iterative tabulation
    int* dp = new int[h + 1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= h; i++) {
        int a = dp[i - 1];
        int b = dp[i - 2];
        int temp1 = (int)(((long)(a) * a) % mod);
        int temp2 = (int)((2 * (long)(a) * b) % mod);
        dp[i] = (temp1 + temp2) % mod;
        // dp[i] = ((2 * a * b) % mod + (a * a) % mod) % mod;
    }
    return dp[h];
}
int main() {
    // cout << fibo2(5) << endl;
    // cout << minStepsToOne2(10) << endl;
    // cout << staircase1(2) << endl;
    // cout << staircase2(10) << endl;
    // cout << minCount(6) << endl;
    // cout << minCount2(12) << endl;
    cout << countBalBT2(6) << endl;
}
