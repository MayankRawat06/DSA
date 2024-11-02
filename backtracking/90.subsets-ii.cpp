class Solution {
    set<vector<int>> res;
    void f(int i, vector<int>& path, vector<int>& v) {
        int n = v.size();
        if(i == n) {
            res.insert(path);
            return;
        }
        path.push_back(v[i]);
        f(i + 1, path, v);
        path.pop_back();
        f(i + 1, path, v);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        sort(v.begin(), v.end());
        vector<int> path;
        f(0, path, v);
        vector<vector<int>> ans;
        for(auto it : res) {
            ans.push_back(it);
        }
        return ans;
    }
};