class Solution {
    int m, n;
    vector<int> dx{-1,0,1,0}, dy{0,-1,0,1};
    void dfs(int r, int c, vector<vector<int>>& v, vector<vector<int>>& vis) {
        vis[r][c] = 1;
        for(int i = 0; i < 4; i++) {
            int nr = r + dx[i], nc = c + dy[i];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && v[nr][nc] == 1 && !vis[nr][nc]) dfs(nr, nc, v, vis);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& v) {
        m = v.size(), n = v[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            if(v[i][0] == 1 && !vis[i][0]) dfs(i, 0, v, vis);
            if(v[i][n - 1] == 1 && !vis[i][n - 1]) dfs(i, n - 1, v, vis);
        }
        for(int j = 0; j < n; j++) {
            if(v[0][j] == 1 && !vis[0][j]) dfs(0, j, v, vis);
            if(v[m - 1][j] == 1 && !vis[m - 1][j]) dfs(m - 1, j, v, vis);
        }
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && v[i][j] == 1) count++;
            }
        }
        return count;
    }
};
