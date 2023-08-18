class Solution {
public:
    string longestPalindrome(string v) {
        int n = v.size(), reslen = 0;
        string res = "";
        for(int i = 0; i < n; i++) {
            int l = i, r = i;
            // odd len
            while(l >= 0 && r < n && v[l] == v[r]) {
                if(r - l + 1 > reslen) {
                    reslen = r - l + 1;
                    res = v.substr(l, r - l + 1);
                }
                l--;
                r++;
            }
            l = i, r = i + 1;
            // even len
            while(l >= 0 && r < n && v[l] == v[r]) {
                if(r - l + 1 > reslen) {
                    reslen = r - l + 1;
                    res = v.substr(l, r - l + 1);
                }
                l--;
                r++;
            }
        }
        return res;
    }
};