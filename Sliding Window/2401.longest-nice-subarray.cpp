class Solution {
public:
    int longestNiceSubarray(vector<int>& v) {
        int n = v.size(), res = 1, i = 0;
        int curr = 0;
        for(int j = 0; j < n; j++) {
            while(i <= j && (curr & v[j]) != 0) {
                curr ^= v[i];
                i++;
            }
            curr |= v[j];
            res = max(res, j - i + 1);
        }
        return res;
    }
};