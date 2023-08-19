// User function Template for C++
class Solution {
    vector<int> d;
    void bfs(int curr, vector<int>& vis, vector<vector<int>>& adj) {
        queue<pair<int, int>> q;
        q.push({curr, 0});
        vis[curr] = 1;
        while(!q.empty()) {
            int node = q.front().first, level = q.front().second;
            q.pop();
            d[node] = min(level, d[node]);
            for(int x : adj[node]) {
                if(!vis[x]) {
                    vis[x] = 1;
                    q.push({x, level + 1});
                }
            }
        }
    }
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n, int m, int src) {
        // Code here
        vector<vector<int>> adj(n);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n, 0);
        d.resize(n, 1e9);
        // for(int i = 0; i < n; i++) {
        //     if(!vis[i]) bfs(i, vis, adj);
        // }
        bfs(src, vis, adj);
        for(int i = 0; i < n; i++) {
            if(d[i] == 1e9) d[i] = -1;
        }
        return d;
    }
};