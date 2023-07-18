vector<int> prime;
class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        if(prime.empty()) {
            int N = 1e6;
            prime.resize(N + 1, true);
            prime[0] = prime[1] = false;
            for(int i = 2; i * i <= N; i++) {
                if(prime[i]) {
                    for(int j = i * i; j <= N; j += i) {
                        prime[j] = false;
                    }
                }
            }
        }
        vector<vector<int>> res;
        for(int i = 2; i <= n / 2; i++) {
            if(prime[n - i] && prime[i]) {
                res.push_back({i, n - i});
            }
        }
        return res;
    }
};