class Solution {
    vector<int> dirx{-1, 0, 1, 0}, diry{0, -1, 0, 1};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        set<pair<int, pair<int, int>>> set;
        vector<vector<int>> dis(m, vector<int>(n, 1e9));
        dis[0][0] = 0;
        set.insert({0, {0, 0}});
        while(!set.empty()) {
            auto it = *set.begin();
            int diff = it.first, x = it.second.first, y = it.second.second;
            int curr = heights[x][y];
            set.erase(it);
            if(x == m - 1 && y == n - 1) break;
            for(int i = 0; i < 4; i++) {
                int r = x + dirx[i], c = y + diry[i];
                if(r >= 0 && r < m && c >= 0 && c < n) {
                    int neighbor = heights[r][c];
                    int d = max(diff, abs(curr - neighbor));
                    if(d < dis[r][c]) {
                        if(dis[r][c] != 1e9) set.erase({dis[r][c], {r, c}});
                        dis[r][c] = d;
                        set.insert({d, {r, c}});
                    }
                }
            }
        }
        return dis[m - 1][n - 1];
    }
};