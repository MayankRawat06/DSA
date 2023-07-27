class Solution {
    bool possible(vector<int>& v, int n, long long mins) {
        long long time = 0, need = n * mins;
        for(long long x : v) {
            time += min(x, mins);
            if(time >= need) return true;
        }
        return false;
    }
public:
    long long maxRunTime(int n, vector<int>& v) {
        int mini = INT_MAX;
        long long sum = 0;
        for(int x : v) {
            mini = min(x, mini);
            sum += x;
        }
        long long low = mini, high = sum / n;
        while(low < high) {
            long long mid = (low + high + 1) / 2;
            if(possible(v, n, mid)) low = mid;
            else high = mid - 1;
        }
        return low;
    }
};