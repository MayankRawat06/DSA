class Solution {
    int res = 0;
    void f(int index, vector<vector<int>>& r, vector<int>& b, int curr) {
        if(index == r.size()) {
            for(int i = 0; i < b.size(); i++) {
                if(b[i] != 0) return;
            }
            res = max(curr, res);
            return;
        }
        f(index + 1, r, b, curr);
        b[r[index][0]] -= 1;
        b[r[index][1]] += 1;
        f(index + 1, r, b, curr + 1);
        b[r[index][0]] += 1;
        b[r[index][1]] -= 1;
    }
public:
    int maximumRequests(int n, vector<vector<int>>& r) {
        vector<int> b(n, 0);
        f(0, r, b, 0);
        return res;
    }
};