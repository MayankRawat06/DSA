class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int, int>>> adj(n + 1);
        for(int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        set<pair<int, int>> set;
        vector<int> dis(n + 1, 1e9);
        vector<int> parent(n + 1);
        dis[1] = 0;
        set.insert({0, 1});
        for(int i = 0; i <= n; i++) parent[i] = i;
        while(!set.empty()) {
            auto it = *set.begin();
            int node = it.second;
            int d = it.first;
            set.erase(it);
            for(auto x : adj[node]) {
                int neighbor = x.first;
                int wt = x.second;
                if(wt + d < dis[neighbor]) {
                    if(dis[neighbor] != 1e9) set.erase({dis[neighbor], neighbor});
                    dis[neighbor] = d + wt;
                    set.insert({dis[neighbor], neighbor});
                    parent[neighbor] = node;
                }
            }
        }
        if(dis[n] == 1e9) return {-1};
        vector<int> res;
        int i = n;
        res.push_back(n);
        while(i != 1) {
            res.push_back(parent[i]);
            i = parent[i];
        } 
        reverse(res.begin(), res.end());
        return res;
    }
};