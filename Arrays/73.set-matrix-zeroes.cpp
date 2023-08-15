class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        // int rows[m] -- v[...][0]
        // int cols[n] -- v[0][...]
        int m = v.size(), n = v[0].size(), col0 = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(v[i][j] == 0) {
                    v[i][0] = 0;
                    if(j != 0) v[0][j] = 0;
                    else col0 = 0;
                }
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(v[i][j] != 0) {
                    if(v[i][0] == 0 || v[0][j] == 0) v[i][j] = 0;
                }
            }
        }
        if(v[0][0] == 0) for(int j = 0; j < n; j++) v[0][j] = 0;
        if(col0 == 0) for(int i = 0; i < m; i++) v[i][0] = 0;
    }
};