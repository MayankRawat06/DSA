class Solution {
    vector<int> dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};
public:
    int orangesRotting(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size();
        int fresh = 0, rotten = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(v[i][j] == 2) {
                    rotten++;
                    q.push({i, j});
                }
                else if(v[i][j] == 1) fresh++;
            }
        }
        int t = -1;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int r = q.front().first, c = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int nr = r + dx[i], nc = c + dy[i];
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && v[nr][nc] == 1) {
                        fresh--;
                        v[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
            t++;
        }
        if(fresh != 0) return -1;
        return t >= 0 ? t : 0;
    }
};