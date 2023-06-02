class Solution {
public:
    void dfs(int curr, vector<vector<int>>& adj, set<int>& vis) {
        int n = adj.size();
        vis.insert(curr);
        for(int i = 0; i < n; i++) {
            if(adj[curr][i] && vis.find(i) == vis.end()) { 
                dfs(i, adj, vis);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            long long h = bombs[i][0], k = bombs[i][1], r2 = (long long)bombs[i][2] * bombs[i][2];
            adj[i][i] = 1;
            for(int j = 0; j < n; j++) {
                long long x = bombs[j][0], y = bombs[j][1];
                long long eqn = ((x - h) * (x - h) + (y - k) * (y - k));
                // cout << eqn << endl;
                if(eqn <= r2) {
                    adj[i][j] = 1;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            set<int> vis;
            dfs(i, adj, vis);
            int curr = vis.size();
            res = max(res, curr);
        }
        return res;
    }
};