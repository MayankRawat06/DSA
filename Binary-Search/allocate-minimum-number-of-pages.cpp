//User function template in C++

class Solution 
{
    int n;
    public:
    //Function to find minimum number of pages.
    bool students(int v[], int mid, int k) {
        int count = 0;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] > mid) return false;
            if(sum + v[i] <= mid) sum += v[i];
            else {
                count++;
                sum = v[i];
            }
        }
        if(sum <= mid) count++;
        else return false;
        if(count <= k) return true;
        else return false;
    }
    int findPages(int v[], int N, int k) 
    {
        //code here
        n = N;
        if(k > n) return -1;
        long long sum = 0;
        int mini = 1e9;
        for(int i = 0; i < n; i++) {
            mini = min(mini, v[i]);
            sum += v[i];
        }
        long long low = mini, high = sum;
        while(low < high) {
            long long mid = low + (high - low) / 2;
            if(students(v, mid, k)) high = mid; // students less or equal to mid -- decrease the pages
            else low = mid + 1; // students more than mid -- increase the pages
        }
        return low;
    }
};