class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int low = 0, high = v.size() - 1;
        int n = v.size();
        while(low < high) {
            int mid = low + (high - low) / 2;
            int res = -9;
            int x = v[mid];
            int prev = mid > 0 ? v[mid - 1] : -1;
            int next = mid < n - 1 ? v[mid + 1] : -1;
            if(prev == x) res = (mid - 1) % 2 ? -1 : 1;
            else if(next == x) res = (mid + 1) % 2 ? 1 : -1;
            else res = 0;
            if(res == 0) return v[mid];
            else if(res == -1) high = mid - 1;
            else low = mid + 1;
        }
        return v[low];
    }
};