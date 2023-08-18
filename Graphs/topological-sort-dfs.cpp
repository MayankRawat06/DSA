class Solution
{
    void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& s) {
        vis[node] = 1;
        for(int x : adj[node]) {
            if(!vis[x]) {
                dfs(x, adj, vis, s);
            }
        }
        s.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    stack<int> s;
	    vector<int> vis(n, 0);
	    for(int i = 0; i < n; i++) {
	        if(!vis[i]) dfs(i, adj, vis, s);
	    }
	    vector<int> res;
	    while(!s.empty()) {
	        res.push_back(s.top());
	        s.pop();
	    }
	    return res;
	}
};