class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int n = v.size();
        int low = 1, high = n - 2;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(v[mid - 1] < v[mid] && v[mid] < v[mid + 1]) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};