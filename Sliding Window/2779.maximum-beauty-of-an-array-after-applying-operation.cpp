class Solution {
public:
    int maximumBeauty(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int i = 0, n = v.size(), res = 0;      
        for(int j = 0; j < n; j++) {
            while(i < j && v[i] + k < v[j] - k) {
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};