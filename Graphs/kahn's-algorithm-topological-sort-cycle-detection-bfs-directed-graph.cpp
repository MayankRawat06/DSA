class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int> in(n, 0);
        queue<int> q;
        for(int i = 0; i < p.size(); i++) {
            adj[p[i][1]].push_back(p[i][0]);
            in[p[i][0]]++;
        }
        for(int i = 0; i < n; i++) {
            if(!in[i]) q.push(i);
        }
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            count++;
            q.pop();
            for(auto x : adj[node]) {
                in[x]--;
                if(!in[x]) q.push(x);
            }
        }
        return count == n;
    }
};