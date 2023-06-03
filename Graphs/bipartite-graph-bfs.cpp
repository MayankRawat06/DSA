class Solution {
    bool bfs(int curr, vector<int>adj[], vector<int>& vis) {
        queue<int> q;
        q.push(curr);
        vis[curr] = 0;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(int x : adj[node]) {
                if(vis[x] == -1) {
                    q.push(x);
                    vis[x] = !vis[node];
                }
                else if(vis[x] == vis[node]) return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    vector<int> vis(n, -1);
	    for(int i = 0; i < n; i++) {
	        if(vis[i] == -1) if(!bfs(i, adj, vis)) return false;
	    }
	    return true;
	}

};