class Solution {
    int n;
    bool isPossible(vector<int>& a, int mid) {
        vector<long long> v(a.begin(), a.end());
        for(int i = 0; i < n - 1; i++) {
            if(v[i] > mid) return false;
            long long buffer = mid - v[i];
            v[i + 1] -= buffer; // can't decrease beyond this
        }
        return v[n - 1] > mid ? false : true;
    }
public:
    int minimizeArrayValue(vector<int>& v) {
        n = v.size();
        int low = 0, high = 1;
        for(int x : v) high = max(high, x);
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(isPossible(v, mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};