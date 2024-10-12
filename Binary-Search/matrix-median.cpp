class Solution{   
    int check(int x, vector<vector<int>> &v) {
        int m = v.size(), n = v[0].size();
        int count = 0;
        bool flag = false;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(v[i][j] <= x) count++;
                else break;
            }
        }
        return count;
        // better to use upper bound on each row - gives index of first element > x
    }
public:
    int median(vector<vector<int>> &v, int m, int n){
        // code here    
        int low = 2001, high = 0;
        for(int i = 0; i < m; i++) {
            low = min(low, v[i][0]);
            high = max(high, v[i][n - 1]);
        }
        // median has half elements <= median and half >= median in a sorted array
        while(low < high) {
            int mid = low + (high - low) / 2;
            int count = check(mid, v);
            int ideal = (n * m - 1) / 2;
            if(count <= ideal) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};