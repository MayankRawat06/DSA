class Solution {
    queue<pair<pair<int, int>, int>> q;
    vector<int> delrow{-1, 0, 1, 0}, delcol{0, -1, 0, 1}; 
    void dfs(int r, int c, vector<vector<int>>& grid, set<pair<int, int>>& vis) {
        int n = grid.size();
        vis.insert({r, c});
        q.push({{r, c}, 0});
        for(int i = 0; i < 4; i++) {
            int nr = delrow[i] + r, nc = delcol[i] + c;
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1 && vis.find({nr, nc}) == vis.end()) {
                dfs(nr, nc, grid, vis);
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int, int>> vis;
        // find first island and mark it all visited
        bool flag = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dfs(i, j, grid, vis);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        // iterate through each visited land and run bfs to find min distance to reach second island
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int r = q.front().first.first, c = q.front().first.second, d = q.front().second;
                q.pop();
                vis.insert({r, c});
                for(int k = 0; k < 4; k++) {
                    int nr = r + delrow[k], nc = c + delcol[k];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n  && vis.find({nr, nc}) == vis.end()) {
                        if(grid[nr][nc] == 1) return d;
                        if(grid[nr][nc] == 0) {
                            vis.insert({nr, nc});
                            q.push({{nr, nc}, d + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};