class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        int i = 0, j = 0, m = f.size(), n = s.size();
        vector<vector<int>> res;
        while(i < m && j < n) {
            int start = max(f[i][0], s[j][0]), end = min(f[i][1], s[j][1]);
            if(start <= end) res.push_back({start, end});
            if(f[i][1] > s[j][1]) j++;
            else i++;
        }
        return res;
    }
};