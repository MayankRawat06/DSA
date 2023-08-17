class Solution {
public:
    int maximumProduct(vector<int>& v, int k) {
        int n = v.size(), mod = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> pq;
        long long res = 1;
        for(int x : v) pq.push(x);
        while(!pq.empty() && k > 0) {
            int x = pq.top(); pq.pop();
            x += 1;
            k--;
            pq.push(x);
        }
        while(!pq.empty()) {
            res *= pq.top();
            res %= mod;
            pq.pop();
        }
        return res % mod;
    }
};