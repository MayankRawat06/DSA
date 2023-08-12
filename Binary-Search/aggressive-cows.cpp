// User function Template for C++

class Solution {
    bool isPossible(vector<int> &v, int k, int mid) {
        int n = v.size();
        int count = 1, prev = v[0];
        for(int i = 1; i < n; i++) {
            if(v[i] - prev >= mid) {
                count++;
                prev = v[i];
                if(count >= k) return true;
            }
        }
        return count >= k;
    }
public:

    int solve(int n, int k, vector<int> &v) {
    
        // Write your code here
        sort(v.begin(), v.end());
        int low = 1, high = v[n - 1] - v[0];
        while(low < high) {
            int mid = (low + high + 1) / 2;
            if(isPossible(v, k, mid)) low = mid;
            else high = mid - 1;
        }
        return low;
    }
};