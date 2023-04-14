class Solution {
  public:
     void topoSort(int curr, vector<vector<pair<int, int>>>& adj, vector<int>& vis, stack<int>& s) {
         vis[curr] = 1;
         for(auto x : adj[curr]) {
             if(!vis[x.first]) topoSort(x.first, adj, vis, s);
         }
         s.push(curr);
     }
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        vector<int> vis(n, 0);
        stack<int> s;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) topoSort(i, adj, vis, s);
        }
        vector<int> d(n, 1e9);
        d[0] = 0;
        while(!s.empty()) if(s.top() != 0) s.pop(); else break;
        while(!s.empty()) {
            int node = s.top(); s.pop();
            int dist = d[node];
            for(auto x : adj[node]) {
                d[x.first] = min(dist + x.second, d[x.first]);
            }
        }
        for(int i = 0; i < n; i++) {
            if(d[i] == 1e9) d[i] = -1;
        }
        return d;
    }
};