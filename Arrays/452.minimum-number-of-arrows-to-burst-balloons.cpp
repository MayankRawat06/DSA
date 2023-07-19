class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        int count = n;
        int s1 = v[0][0], e1 = v[0][1], overlap = 0;
        for(int i = 1; i < n; i++) {
            int s2 = v[i][0], e2 = v[i][1];
            if(s2 > e1) {
                s1 = s2;
                e1 = e2;
            }
            else {
                s1 = max(s1, s2);
                e1 = min(e1, e2);
                count--;
            }
        }
        return count;
    }
};