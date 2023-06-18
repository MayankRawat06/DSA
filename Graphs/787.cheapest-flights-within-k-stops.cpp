class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int s, int d, int k) {
        vector<vector<pair<int, int>>> adj(n); 
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> q;  // stops node distance
        vector<int> dis(n, INT_MAX);
        dis[s] = 0; 
        q.push({0, {s, 0}});
        while(!q.empty()) {
            int stops = q.front().first, d = q.front().second.second, node = q.front().second.first; q.pop();
            if(stops > k) break;
            for(auto x : adj[node]) {
                int neighbor = x.first, dx = x.second;
                if(d + dx < dis[neighbor] && stops <= k) {
                    dis[neighbor] = d + dx;
                    q.push({stops + 1, {neighbor, d + dx}});
                }
            }
        }
        return dis[d] == INT_MAX ? -1 : dis[d];
    }
};