class Solution {
    vector<int> dx{-1,0,1,0}, dy{0,-1,0,1};
    int m, n;
    int f(int i, int j, int k, vector<vector<int>>& v) {
        if(i < 0 || i >= m || j < 0 || j >= n || v[i][j] == -1) return 0;
        if(v[i][j] == 2) return k == 0;
        v[i][j] = -1;
        int count = 0;
        for(int x = 0; x < 4; x++) {
            count += f(i + dx[x], j + dy[x], k - 1, v);
        }
        v[i][j] = 0;
        return count;
    }
public:
    int uniquePathsIII(vector<vector<int>>& v) {
        m = v.size(), n = v[0].size();
        int r = -1, c = -1, k = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(v[i][j] == 0) k++;
                if(v[i][j] == 1) r = i, c = j;
            }
        }
        return f(r, c, k + 1, v);
    }
};