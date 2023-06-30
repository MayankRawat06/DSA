class Solution {
    vector<int> dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};
    bool possible(int index, int m, int n, vector<vector<int>>& a) {
        vector<vector<int>> v(m, vector<int>(n, 0));
        // vector<vector<int>> vis(m, vector<int>(n, 0)); no need 
        for(int i = 0; i <= index; i++) {
            int r = a[i][0] - 1, c = a[i][1] - 1;
            v[r][c] = 1;
        }
        queue<pair<int, int>> q;
        for(int j = 0; j < n; j++) {
            if(!v[0][j]) {
                q.push({0, j});
                v[0][j] = 1;
            }
        }
        while(!q.empty()) {
            int r = q.front().first, c = q.front().second;
            if(r == m - 1) return true;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !v[nr][nc]) {
                    q.push({nr, nc});
                    v[nr][nc] = 1;
                }
            }
        }
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0, high = cells.size() - 1;
        while(low < high) {
            int mid = (low + high + 1) / 2;
            if(possible(mid, row, col, cells)) low = mid;
            else high = mid - 1;
        }
        return low + 1;
    }
};