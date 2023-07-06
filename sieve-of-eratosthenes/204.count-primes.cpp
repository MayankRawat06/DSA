vector<bool> prime;
class Solution {
public:
    int countPrimes(int n) {
        if(prime.empty()) {
            int N = 5 * 1e6;
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
        int count = 0;
        for(int i = 2; i < n; i++) {
            if(prime[i]) count++;
        }
        return count;
    }
};