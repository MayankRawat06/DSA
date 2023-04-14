class Solution {
    bool dfs(int curr, int parent, vector<int> adj[], vector<int>& vis) {
        vis[curr] = 1;
        for(auto x : adj[curr]) {
            if(!vis[x]) {
                if(dfs(x, curr, adj, vis)) return true;
            }
            else if(x != parent) return true;
        }
        return false;
    }
    bool bfs(int curr, vector<int> adj[], vector<int>& vis) {
        queue<pair<int, int>> q;
        vis[curr] = 1;
        q.push({curr, -1});
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto x : adj[node]) {
                if(!vis[x]) {
                    vis[x] = 1;
                    q.push({x, node});
                }
                else if(x != parent) return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    
    bool isCycle(int n, vector<int> adj[]) {
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) 
                if(dfs(i, -1, adj, vis)) return true;
        }
        return false;
    }
};