class Solution {
public:
    int getHours(int speed, vector<int>& v) {
        int hours = 0;
        for(int x : v) {
            hours += x / speed;
            if(x % speed) hours += 1;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& v, int h) {
        int n = v.size(); 
        int low = 1, high = 1;
        for(int x : v) {
            high = max(high, x);
        }
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(getHours(mid, v) <= h) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};