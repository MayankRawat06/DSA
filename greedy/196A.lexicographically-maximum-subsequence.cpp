#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl "\n"
#define int long long
string f(string& s){
    string res = "";
    int lastIndex = -1;
    int n = s.size();
    for(char c = 'z'; c >= 'a'; c--) {
        for(int i = lastIndex + 1; i < n; i++) {
            if(c == s[i]) {
                res += c;
                lastIndex = i;
            }
        }
    }
    return res;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s = "";
    cin >> s;
    int n = s.size();
    cout << f(s) << endl;
    return 0;
}
