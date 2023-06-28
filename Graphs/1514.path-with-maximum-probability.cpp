class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succ[i]});
            adj[edges[i][1]].push_back({edges[i][0], succ[i]});
        }
        vector<double> dis(n, 0);
        priority_queue<pair<double, int>> pq;
        dis[start] = 1;
        pq.push({1, start});
        while(!pq.empty()) {
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            for(auto x : adj[node]) {
                int neighbor = x.first;
                double nprob = x.second;
                if(dis[neighbor] < prob * nprob ) {
                    dis[neighbor] = prob * nprob;
                    pq.push({dis[neighbor], neighbor});
                }
            }
        }
        return dis[end];
    }
};