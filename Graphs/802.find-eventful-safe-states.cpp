class Solution {
    bool dfs(int curr, vector<int>& vis, vector<int>& pathvis, set<int>& safe, vector<vector<int>>& adj) {
        vis[curr] = 1;
        pathvis[curr] = 1;
        for(int x : adj[curr]) {
            if(!vis[x]) {
                if(dfs(x, vis, pathvis, safe, adj)) return true;
            }
            else if(pathvis[x]) return true;
        }
        pathvis[curr] = 0;
        safe.insert(curr);
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0), pathvis(n, 0);
        set<int> safe;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, vis, pathvis, safe, adj);
            }
        }
        vector<int> res(safe.begin(), safe.end());
        return res;
    }
};