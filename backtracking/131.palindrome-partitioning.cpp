class Solution {
    vector<vector<string>> res;
    bool check(string& s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    void f(int index, string s, vector<string>& path) {
        int n = s.size();
        if(index >= n) {
            res.push_back(path);
            return;
        }
        for(int j = index; j < n; j++) {
            if(check(s, index, j)) {
                path.push_back(s.substr(index, j - index + 1));
                f(j + 1, s, path);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        f(0, s, path);
        return res;
    }
};