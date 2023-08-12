class Solution {
public:
    int longestContinuousSubstring(string v) {
        int n = v.size(), count = 1, res = 1;
        for(int i = 1; i < n; i++) {
            if(v[i] - v[i - 1] == 1) count++;
            else {
                res = max(res, count);
                count = 1;
            }
        }
        return max(res, count);
    }
};