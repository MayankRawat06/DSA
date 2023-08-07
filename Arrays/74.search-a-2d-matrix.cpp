class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int m = v.size(), n = v[0].size(), low = 0, high = m * n - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int x = v[mid / n][mid % n];
            if(x == target) return true;
            else if(x < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};
