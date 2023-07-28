class Solution{
    int n;
    vector<string> res;
    vector<vector<bool>> vis;
    void f(int i, int j, string path, vector<vector<int>>& v) {
        if(i < 0 || i >= n || j < 0 || j >= n || !v[i][j] || vis[i][j]) return;
        if(i == n - 1 && j == n - 1) {
            res.push_back(path);
            return;
        }
        vis[i][j] = 1;
        f(i + 1, j, path + 'D', v);
        f(i, j - 1, path + 'L', v);
        f(i, j + 1, path + 'R', v);
        f(i - 1, j, path + 'U', v);
        vis[i][j] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int sz) {
        // Your code goes here
        n = sz;
        vis.resize(n, vector<bool>(n, 0));
        string curr = "";
        f(0, 0, curr, m);
        return res;
    }
};