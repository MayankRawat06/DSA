class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> res;
        int n = v.size();
        int s1, e1, s2, e2;
        int i = 1;
        s1 = v[0][0];
        e1 = v[0][1];
        while(i < n) {
            s2 = v[i][0];
            e2 = v[i][1];
            if(e1 < s2) {
                res.push_back({s1,e1});
                s1 = s2;
                e1 = e2;
            }
            else {
                s1 = min(s1, s2);
                e1 = max(e1, e2);
            }
            i++;
        }
        res.push_back({s1,e1});
        return res;
    }
};