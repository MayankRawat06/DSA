class Solution {
    int longestSubarray(vector<int>& v, long long k) {
        if(k == 0) return 0;
        int i = 0, res = -1, n = v.size();
        long long sum = 0;
        for(int j = 0; j < n; j++) {
            sum += v[j];
            while(i < j && sum > k) {
                sum -= v[i++];
            }
            if(sum == k) res = max(res, j - i + 1);
        }
        return res;
    }
public:
    int minOperations(vector<int>& v, int x) {
        long long sum = 0, n = v.size();
        for(int x : v) sum += x;
        int res = longestSubarray(v, sum - x);
        return res == -1 ? - 1 : n - res;
    }
};