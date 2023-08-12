// using prefix max and suffix max
class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        vector<int> p(n), s(n);
        p[0] = v[0];
        s[n - 1] = v[n - 1];
        for(int i = 1; i < n; i++) p[i] = max(v[i], p[i - 1]);
        for(int i = n - 2; i >= 0; i--) s[i] = max(v[i], s[i + 1]);
        int res = 0;
        for(int i = 0; i < n; i++) res += min(p[i], s[i]) - v[i];
        return res;
    }
};

// using two pointers
class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n - 1, lmax = 0, rmax = 0, res = 0;
        while(l < r) {
            if(v[l] <= v[r]) {
                if(v[l] >= lmax) lmax = v[l];
                else res += (lmax - v[l]);
                l++;
            }
            else {
                if(v[r] >= rmax) rmax = v[r];
                else res += (rmax - v[r]);
                r--;
            }
        }
        return res;
    }
};