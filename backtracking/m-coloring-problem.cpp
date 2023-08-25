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