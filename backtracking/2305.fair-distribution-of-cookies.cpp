class Solution {
    int res = INT_MAX;
    void f(int index, vector<int>& c, vector<int>& v) {
        int n = v.size();
        int k = c.size();
        if(index == n) {
            int val = INT_MIN;
            for(int i = 0; i < k; i++) {
                val = max(c[i], val);
            }
            res = min(res, val);
            return;
        }
        int cookie = v[index];
        // cout << cookie << endl;
        for(int i = 0; i < k; i++) {
            c[i] += cookie;
            f(index + 1, c, v);
            c[i] -= cookie;
        }   
    }
public:
    int distributeCookies(vector<int>& v, int k) {
        vector<int> c(k, 0);
        f(0, c, v);
        return res;
    }
};