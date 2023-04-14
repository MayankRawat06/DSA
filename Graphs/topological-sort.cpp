class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    queue<int> q;
	    vector<int> indegree(n, 0);
	    for(int i = 0; i < n; i++) {
	        for(int node : adj[i]) {
	            indegree[node]++;
	        }
	    }
	    for(int i = 0; i < n; i++) {
	        if(indegree[i] == 0) q.push(i);
	    }
	    vector<int> res;
	    while(!q.empty()) {
	        int node = q.front(); q.pop();
	        res.push_back(node);
	        for(int x : adj[node]) {
	            indegree[x]--;
	            if(indegree[x] == 0) q.push(x);
	        }
	    }
	    return res;
	}
};