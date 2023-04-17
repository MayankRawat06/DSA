class Solution {
    vector<int> dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> dest) {
       int m = grid.size(), n = grid[0].size();
        if(grid[src.first][src.second] == 0) return -1;
        vector<vector<int>> dis(m, vector<int>(n, 1e9));
        set<pair<int, pair<int, int>>> set;
        dis[src.first][src.second] = 0;
        set.insert({0, {src.first, src.second}});
        while(!set.empty()) {
            auto it = *set.begin();
            int d = it.first;
            int row = it.second.first, col = it.second.second;
            set.erase(it);
            for(int i = 0; i < 4; i++) {
                int delx = dx[i], dely = dy[i];
                int r = row + delx, c = col + dely;
                if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                    if(d + 1 < dis[r][c]) {
                        if(dis[r][c] != 1e9) set.erase({dis[r][c], {r, c}});
                        dis[r][c] = d + 1;
                        set.insert({dis[r][c], {r, c}});
                    }
                }
            }
        }
        return dis[dest.first][dest.second] == 1e9 ? -1 : dis[dest.first][dest.second];
        
    }
};