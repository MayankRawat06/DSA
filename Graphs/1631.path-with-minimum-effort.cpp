class Solution {
    vector<int> dirx{-1, 0, 1, 0}, diry{0, -1, 0, 1};
public:
    int minimumEffortPath(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size();
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dis(m, vector<int>(n, 1e9));
        dis[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int r = it.second.first, c = it.second.second, effTillNow = it.first, height = v[r][c];
            if(r == m - 1 && c == n - 1) break;
            for(int i = 0; i < 4; i++) {
                int nr = r + dirx[i], nc = c + diry[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int adjHeight = v[nr][nc];
                    int eff = max(effTillNow, abs(adjHeight - height));
                    if(dis[nr][nc] > eff) {
                        dis[nr][nc] = eff;
                        pq.push({eff, {nr, nc}});
                    }
                }
            }
        }
        return dis[m - 1][n - 1];
    }
};