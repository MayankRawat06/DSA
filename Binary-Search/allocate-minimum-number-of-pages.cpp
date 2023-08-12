//User function template in C++

class Solution 
{
    int n;
    public:
    //Function to find minimum number of pages.
    int students(int v[], int mid) {
        int count = 0;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            if(sum + v[i] <= mid) sum += v[i];
            else {
                count++;
                sum = v[i];
            }
        }
        // cout << sum << endl;
        if(sum <= mid) return count + 1;
        else return 1e9;
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
            if(students(v, mid) <= k) high = mid; // students less or equal to mid -- decrease the pages
            else low = mid + 1; // students more than mid -- increase the pages
        }
        return low;
    }
};