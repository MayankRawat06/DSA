class Solution {
    vector<vector<int>> res;
    void f(int i, vector<int>& path, vector<int>& v, int k) {
        int n = v.size();
        if(k < 0) return;
        if(k == 0) {
            res.push_back(path);
            return;
        }
        if(i == n) return;
        // pick -- multiple times
        path.push_back(v[i]);
        f(i, path, v, k - v[i]);
        path.pop_back();
        // not pick
        f(i + 1, path, v, k);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& v, int k) {
        vector<int> path;
        f(0, path, v, k);
        return res;
    }
};