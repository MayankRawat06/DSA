// using queue -- better - eliminate log n of complexity
class Solution {
    vector<int> dx{-1, -1, -1, 0, 0, 1, 1, 1}, dy{-1, 0, 1, -1, 1, -1, 0, 1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        queue<pair<int, pair<int, int>>> q;
        dis[0][0] = 1;
        q.push({1, {0, 0}});
        while(!q.empty()) {
            auto it = q.front();
            int d = it.first;
            int row = it.second.first, col = it.second.second;
            q.pop();
            for(int i = 0; i < 8; i++) {
                int delx = dx[i], dely = dy[i];
                int r = row + delx, c = col + dely;
                if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0) {
                    if(d + 1 < dis[r][c]) {
                        dis[r][c] = d + 1;
                        q.push({dis[r][c], {r, c}});
                    }
                }
            }
        }
        return dis[n - 1][n - 1] == 1e9 ? -1 : dis[n - 1][n - 1];
    }
};


// using set
class Solution {
    vector<int> dx{-1, -1, -1, 0, 0, 1, 1, 1}, dy{-1, 0, 1, -1, 1, -1, 0, 1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        set<pair<int, pair<int, int>>> set;
        dis[0][0] = 1;
        set.insert({1, {0, 0}});
        while(!set.empty()) {
            auto it = *set.begin();
            int d = it.first;
            int row = it.second.first, col = it.second.second;
            set.erase(it);
            for(int i = 0; i < 8; i++) {
                int delx = dx[i], dely = dy[i];
                int r = row + delx, c = col + dely;
                if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0) {
                    if(d + 1 < dis[r][c]) {
                        if(dis[r][c] != 1e9) set.erase({dis[r][c], {r, c}});
                        dis[r][c] = d + 1;
                        set.insert({dis[r][c], {r, c}});
                    }
                }
            }
        }
        return dis[n - 1][n - 1] == 1e9 ? -1 : dis[n - 1][n - 1];
    }
};
