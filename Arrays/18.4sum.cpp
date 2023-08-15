class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int t) {
        int n = v.size();
        sort(v.begin(), v.end());
        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            if(i > 0 && v[i - 1] == v[i]) continue;
            for(int j = i + 1; j < n; j++) {
                if(j > i + 1 && v[j - 1] == v[j]) continue;
                int k = j + 1;
                int l = n - 1;
                while(k < l) {
                    long long sum = v[i] + v[j];
                    sum += v[k];
                    sum += v[l];
                    if(sum < t) k++;
                    else if(sum > t) l--;
                    else {
                        res.push_back({v[i], v[j], v[k], v[l]});
                        k++;
                        l--;
                        while(k < l && v[k - 1] == v[k]) k++;
                        while(k < l && v[l + 1] == v[l]) l--;
                    }
                }
            }
        }
        return res;
    }
};