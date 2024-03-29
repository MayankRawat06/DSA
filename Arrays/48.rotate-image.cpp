class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int n = v.size();
        // make transpose
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(v[i][j], v[j][i]);
            }
        }
        // reverse every row
        for(int i = 0; i < n; i++) reverse(v[i].begin(), v[i].end());
    }
};