#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl "\n"
#define int long long
int f(vector<int>& start, vector<int>& t) {
    sort(start.begin(), start.end());
    sort(t.begin(), t.end());
    int n = t.size();
    int k = 0;
    int res = 0;
    for(int i = n - 1; i >= 0; i-=4) {
        res = max(start[k++] + t[i], res);
    }
    return res;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 2;
    vector<int> start{10, 20}, t{2,3,1,2,5,8,4,3};
    cout << f(start, t) << endl;
    return 0;
}