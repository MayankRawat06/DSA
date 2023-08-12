class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int n = v.size(), count = 0, res = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] == 1) count++;
            else {
                res = max(res, count);
                count = 0;
            }
        }
        return max(res, count);
    }
};