class Solution {
public:
    int minAbsoluteDifference(vector<int>& v, int x) {
        int n = v.size();
        set<int> s;
        int mini = 1e9;
        for(int i = n - 1; i >= 0; i--) {
            s.insert(v[i]);
            if(i - x >= 0) {
                int z = v[i - x];
                auto it = s.lower_bound(z);
                int e = 1e9;
                if(it != s.end()) e = *it;
                mini = min(mini, abs(e - z));
                if(it != s.begin()) {
                    it--;
                    mini = min(mini, abs(*it - z));
                }
            }
        }
        return mini;
    }
};