class Solution {
    int pivot(vector<int>& v) {
        int n = v.size(), low = 0, high = n - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(v[mid] > v[high]) low = mid + 1;
            else high = mid;
        }
        return low;
    } // return index of pivot
    int bs(int low, int high, vector<int>& v, int k) {
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(v[mid] < k) low = mid + 1;
            else high = mid;
        }
        return v[low] == k ? low : -1;
    }
public:
    int search(vector<int>& v, int target) {
        int n = v.size();
        int p = pivot(v);
        int ansl = bs(0, p - 1, v, target);
        int ansr = bs(p, n - 1, v, target);
        if(ansl == ansr && ansl == -1) return -1;
        return ansl == -1 ? ansr : ansl;
    }
};