class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            if(i > 0 && v[i - 1] == v[i]) continue;
            int j = i + 1;
            int k = n - 1;
            while(j < k) {
                int sum = v[i] + v[j] + v[k];
                if(sum < 0) {
                    j++;
                }
                else if(sum > 0) {
                    k--;
                }
                else {
                    res.push_back({v[i], v[j], v[k]});
                    j++;
                    k--;
                    while(j < k && v[k] == v[k + 1]) k--;
                    while(j < k && v[j] == v[j - 1]) j++;
                }
            }
        }
        return res;
    }
};