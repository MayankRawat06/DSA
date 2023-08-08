class Solution {
public:
    // always look out for sorted half and check if the element lies within that, based on that half your search space.
    int search(vector<int>& v, int k) {
        int n = v.size(), low = 0, high = n - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(v[mid] == k) return mid; // element found
            // left half sorted
            if(v[low] <= v[mid]) {
                // search in left half now 
                if(v[low] <= k && k <= v[mid]) high = mid;
                else low = mid + 1;
            }
            else { // right half sorted
                // search in right half now 
                if(v[mid] <= k && k <= v[high]) low = mid;
                else high = mid - 1;
            }
        }
        return -1;
        // element not found
    }
};