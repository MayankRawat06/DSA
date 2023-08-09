class Solution {
public:
    int findMin(vector<int>& v) {
        int low = 0, high = v.size() - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(v[mid] > v[high]) low = mid + 1; // pivot must be in right half
            else high = mid; // include this element -- it can be the minimum too and pivot is in left
        }
        return v[low];
    }
};