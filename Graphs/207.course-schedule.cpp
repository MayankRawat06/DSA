class Solution {
    bool cycle(int curr, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathvis) {
        vis[curr] = 1;
        pathvis[curr] = 1;
        for(int x : adj[curr]) {
            if(!vis[x]) {
                if(cycle(x, adj, vis, pathvis)) return true;
            }
            else {
                if(pathvis[x]) return true;
            }
        }
        pathvis[curr] = 0;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& v) {
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<vector<int>> adj(n);
        for(auto x : v) {
            adj[x[1]].push_back(x[0]);
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(cycle(i, adj, vis, pathvis)) return false;
            }
        }
        return true;
    }
};