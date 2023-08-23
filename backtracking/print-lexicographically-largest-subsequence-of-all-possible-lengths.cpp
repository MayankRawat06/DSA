#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl "\n"
#define int long long
vector<string> res;
void f(int i, string& s, string curr){
    int n = s.size();
    if(i >= n) {
        int z = curr.size();
        res[z] = max(res[z], curr);
        return;
    }
    f(i + 1, s, curr + s[i]);
    f(i + 1, s, curr);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s = "";
    cin >> s;
    int n = s.size();
    res.resize(n + 1, "");
    string curr = "";
    f(0, s, curr);
    for(auto z : res) cout << z << endl;
    return 0;
}