class Solution {
    double check(vector<int>& v, double speed) {
        double hours = 0;
        int n = v.size();
        for(int i = 0; i < n - 1; i++) hours += ceil(v[i] / speed);
        hours += v[n - 1] / speed;
        return hours;
    }
public:
    int minSpeedOnTime(vector<int>& v, double hour) {
        int low = 1, high = 1e9;
        if(check(v, high) > hour) return -1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(check(v, mid) <= hour) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};