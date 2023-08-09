class Solution {
    int n;
    bool possible(vector<int>& v, int mid, int p) {
        int i = 0;
        while(i < n - 1) {
            int d = v[i + 1] - v[i];
            if(d <= mid) {
                p--;
                i += 2;
            }
            else i++;
            if(p == 0) return true;
        }
        return false;
    }
public:
    int minimizeMax(vector<int>& v, int p) {
        n = v.size();
        if(p == 0) return 0;
        sort(v.begin(), v.end());
        int low = 0, high = v[n - 1] - v[0];
        while(low < high) {
            int mid = low + (high - low) / 2; // required max diff
            if(possible(v, mid, p)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};