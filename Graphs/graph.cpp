#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int curr, int n, vector<int> adj[], vector<int>& visited, vector<int>& res) {
    queue<int> q;
    q.push(curr);
    visited[curr] = 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto x : adj[node]) {
            if(!visited[x]) {
                visited[x] = 1;
                q.push(x);
            }
        }
        res.push_back(node);
    }
    return res;
}
vector<int> bfsOfGraph(int n, vector<int> adj[]) {
    vector<int> visited(n, 0);
    vector<int> res;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) bfs(i, n, adj, visited, res);
    }
    return res;
}

vector<int> dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& res, int n) {
    vis[node] = 1;
    res.push_back(node);
    for(auto x : adj[node]) {
        if(!vis[x]) dfs(x, adj, vis, res, n);
    }
    return res;
}
vector<int> dfsOfGraph(int n, vector<int> adj[]) {
    vector<int> vis(n, 0);
    vector<int> res;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(i, adj, vis, res, n);
    }
    return res;
}

int main() {
    int m, n;
    // cin >> n >> m ;
    // vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    // for(int i = 0; i < m; i++) {
    //     int node1, node2;
    //     cin >> node1 >> node2;
    //     adj[node1][node2] = 1;
    //     adj[node2][node1] = 1;
    // } // matrix
    vector<vector<int>>adjl(n + 1);
    for(int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        adjl[node1].push_back(node2);
        adjl[node2].push_back(node1);
    }
}
