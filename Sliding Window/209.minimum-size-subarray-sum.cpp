class Solution {
public:
    int minSubArrayLen(int k, vector<int>& v) {
        int i = 0, sum = 0, n = v.size(), mini = INT_MAX;
        for(int j = 0; j < n; j++) {
            sum += v[j];
            while(i < n && sum >= k) {
                mini = min(mini, j - i + 1);
                sum -= v[i];
                i++;
            }
        }
        return mini > 1e9 ? 0 : mini;
    }
};