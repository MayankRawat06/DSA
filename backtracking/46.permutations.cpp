class Solution {
    vector<vector<int>> res;
    int n;
    void f(int index, vector<int>& v) {
        if(index >= n) {
            res.push_back(v);
            return;
        }
        for(int i = index; i < n; i++) {
            swap(v[index], v[i]);
            f(index + 1, v);
            swap(v[index], v[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& v) {
        n = v.size();
        f(0, v);
        return res;
    }
};