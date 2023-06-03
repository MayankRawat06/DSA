class Solution {
    bool dfs(int curr, vector<int>adj[], vector<int>& vis, bool color) {
        vis[curr] = color;
        for(int x : adj[curr]) {
            if(vis[x] == -1) {
                if(!dfs(x, adj, vis, !color)) return false;
            }
            else {
                if(vis[x] == color) return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    vector<int> vis(n, -1);
	    for(int i = 0; i < n; i++) {
	        if(vis[i] == -1) if(!dfs(i, adj, vis, 0)) return false;
	    }
	    return true;
	}

};