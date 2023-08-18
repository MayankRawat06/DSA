class Solution {
    bool bfs(int curr, vector<vector<int>>& adj, vector<int>& vis) {
        queue<int> q; 
        q.push(curr);
        vis[curr] = 0;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(int x : adj[node]) {
                if(vis[x] == -1) {
                    vis[x] = !vis[node];
                    q.push(x);
                }
                else {
                    if(vis[x] == vis[node]) return false;
                }
            }
        }
        return true;
    }
    bool dfs(int curr, int color, vector<vector<int>>& adj, vector<int>& vis) {
        vis[curr] = color;
        for(int x : adj[curr]) {
            if(vis[x] == -1) {
                if(!dfs(x, !color, adj, vis)) return false;
            }
            else {
                if(vis[x] == color) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, -1);
        for(int i = 0; i < n; i++) {
            if(vis[i] == -1) {
                // if(!bfs(i, adj, vis)) return false;
                if(!dfs(i, 0, adj, vis)) return false;
            }
        }
        return true;
    }
};