class Solution {
public:
    bool search(vector<int>& v, int k) {
        int n = v.size(), low = 0, high = n - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(v[mid] == k) return true;
            if(v[low] == v[mid] && v[high] == v[mid]) { // edge case
                low++;
                high--;
                continue;
            }
            if(v[low] <= v[mid]) { // left part sorted
                if(v[low] <= k && k <= v[mid]) high = mid - 1;
                else low = mid + 1;
            }
            else { // right part sorted
                if(v[mid] <= k && k <= v[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return false;
        
    }
};