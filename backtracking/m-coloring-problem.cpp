class Solution{
    int n, m;
    bool possible(int node, bool adj[101][101], int k, vector<int>& color) {
        for(int i = 0; i < n; i++) {
            if(i != node && adj[node][i] == 1 && color[i] == k) return false;
        }
        return true;
    }
    bool f(int node, bool adj[101][101], vector<int>& color) {
        if(node == n) return true;
        for(int k = 1; k <= m; k++) {
            if(possible(node, adj, k, color)) {
                color[node] = k;
                if(f(node + 1, adj, color)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool adj[101][101], int m, int n) {
        // your code here
        this -> n = n;
        this -> m = m;
        vector<int> color(n, 0);
        return f(0, adj, color);
    }
};


// alternative solution with different params

class Solution {
    bool possible(int node, vector<vector<int>>& adj, vector<int>& vis, int color) {
        for(int x : adj[node]) {
            if(vis[x] == color) return false;
        }
        return true;
    }
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& adj, int m) {
        int n = vis.size();
        if(node == n) return true;
        for(int i = 0; i < m; i++) {
            vis[node] = i;
            if(possible(node, adj, vis, i)) {
                if(dfs(node + 1, vis, adj, m)) return true;
            }
            vis[node] = -1;
        }
        return false;
    }
public:
    bool graphColoring(int n, vector<pair<int, int>>& v, int m) {
        // code here
        vector<vector<int>> adj(n);
        for(int i = 0; i < v.size(); i++) {
            pair<int, int> e = v[i];
            // ignore self-loops
            if(e.first != e.second) {
                adj[e.first].push_back(e.second);
                adj[e.second].push_back(e.first);
            }
        }
        vector<int> vis(n, -1);
        return dfs(0, vis, adj, m);
    }
};
