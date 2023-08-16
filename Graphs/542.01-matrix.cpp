class Solution {
    vector<int> dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size();
        // take 0s to 1s
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> res(m, vector<int>(n, 0));
        queue<vector<int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(v[i][j] == 0) {
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()) {
            auto x = q.front(); q.pop();
            int r = x[0], c = x[1], d = x[2];
            res[r][c] = d;
            for(int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc, d + 1});
                } 
            }
        }
        return res;
    }
};