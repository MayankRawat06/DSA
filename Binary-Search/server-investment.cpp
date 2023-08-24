#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl "\n"
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> f{8, 9}, s{4, 3}, sell{4, 2}, up{4, 5};
    int n = f.size();
    vector<int> res(n);
    for(int i = 0; i < n; i++) {
        int low = 0, high = s[i];
        while(low < high) {
            int mid = (low + high + 1) / 2;
            int rem = f[i] - up[i] * mid + sell[i] * (s[i] - mid);
            if(rem >= 0) low = mid;
            else high = mid - 1;
        }
        res[i] = low;
    }
    for(int x : res) cout << x << " ";
    return 0;
}