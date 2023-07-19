class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size();
        int l = 0, r = n - k, sum = 0;
        for(int i = r; i < n; i++) sum += v[i];
        int res = sum;
        while(r < n) {
            sum -= v[r];
            sum += v[l];
            res = max(sum, res);
            l++;
            r++;
        }
        return res;
    }
};