class Solution {
    int n;
    void topo(int curr, vector<int>& indegree, vector<vector<int>>& adj, vector<int>& res) {
        queue<int> q;
        q.push(curr);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            indegree[node] = -1;
            if(node < n) res.push_back(node);
            for(int x : adj[node]) {
                indegree[x]--;
                if(indegree[x] == 0) q.push(x);
            }
        }
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& g, vector<vector<int>>& b) {
        this -> n = n;
        vector<int> heads;
        vector<int> tails;
        for(int i = 0; i < m; i++) {
            heads.push_back(n + 2 * i);
            tails.push_back(n + 2 * i + 1);
        }
        int total = n + m * 2;
        vector<vector<int>> adj(total);
        vector<int> indegree(total, 0);
        for(int i = 0; i < n; i++) {
            if(g[i] != -1) {
                int head = heads[g[i]], tail = tails[g[i]];
                adj[head].push_back(i);
                indegree[i]++;
                adj[i].push_back(tail);
                indegree[tail]++;
            }
            for(int x : b[i]) {
                int from = g[x], to = g[i];
                bool sameGroup = (from == to);
                int in = (sameGroup || to == - 1) ? i : heads[to];
                int out = (sameGroup || from == - 1) ? x : tails[from];
                adj[out].push_back(in);
                indegree[in]++;
            }   
        }
        vector<int> ans;
        for(int i = 0; i < total; i++) {
            if(indegree[i] == 0) topo(i, indegree, adj, ans);
        }
        if(ans.size() != n) return {};
        return ans;
    }
};