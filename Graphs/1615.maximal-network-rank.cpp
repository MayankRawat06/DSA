class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>(n, 0));
        vector<int> degree(n, 0);
        for(auto e : edges) {
            degree[e[0]]++;
            degree[e[1]]++;
            adj[e[0]][e[1]] = 1;
            adj[e[1]][e[0]] = 1;
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int curr = degree[i] + degree[j];
                if(adj[i][j] == 1) curr--;
                res = max(res, curr);
            }
        }
        return res;
    }
};