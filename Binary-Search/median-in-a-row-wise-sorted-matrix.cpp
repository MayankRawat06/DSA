//User function template for C++

class Solution{   
    int check(vector<vector<int>> &v, int mid) {
        int m = v.size(), n = v[0].size(), count = 0;
        for(int i = 0; i < m; i++) {
            count += upper_bound(v[i].begin(), v[i].end(), mid) - v[i].begin();
        }
        return count;
    }
public:
    int median(vector<vector<int>> &v, int r, int c){
        // code here        
        int low = 1, high = 2000;
        int e = (r * c) / 2;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int lessThanEqualTo = check(v, mid);
            if(lessThanEqualTo > e) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};