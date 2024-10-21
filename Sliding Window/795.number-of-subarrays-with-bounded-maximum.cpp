class Solution {
    long long check(int cap, vector<int>& v) {
        int last = -1;
        long long count = 0;
        int n = v.size();
        for(int i = 0; i < n; i++) {
            if(v[i] > cap) {
                long long x = i - last - 1;
                count += x * (x + 1) / 2;
                last = i;
            }
        }
        long long x = n - 1 - last;
        return count + (x * (x + 1) / 2);
    }
public:
    int numSubarrayBoundedMax(vector<int>& v, int left, int right) {
        long long res = check(right, v);
        if(left > 0) res -= check(left - 1, v);
        return res;
    }
};