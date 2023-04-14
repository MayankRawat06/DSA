class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int curr, vector<int>& vis, vector<int>& pathvis, vector<int> adj[]) {
        vis[curr] = 1;
        pathvis[curr] = 1;
        for(int x : adj[curr]) {
            if(!vis[x]) {
                if(dfs(x, vis, pathvis, adj)) return true;
            }
            else {
                if(pathvis[x]) return true;
            }
        }
        pathvis[curr] = 0;
        return false;
    }
    bool isCyclic(int n, vector<int> adj[]) {
        queue<int> q;
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            for(int x : adj[i]) {
                indegree[x]++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(int x : adj[node]) {
                indegree[x]--;
                if(indegree[x] == 0) q.push(x);
            }
        }
        for(int i = 0; i < n; i++) {
            if(indegree[i] != 0) return true;
        }
        return false;
    }
};