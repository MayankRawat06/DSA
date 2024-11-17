
// Kadane's Algorithm
// TC = O(n)
// SC = O(1)

class Solution {
public:
    int minSubArrayLen(int k, vector<int>& v) {
        int i = 0, sum = 0, n = v.size(), mini = INT_MAX;
        for(int j = 0; j < n; j++) {
            sum += v[j];
            while(i < n && sum >= k) {
                mini = min(mini, j - i + 1);
                sum -= v[i];
                i++;
            }
        }
        return mini > 1e9 ? 0 : mini;
    }
};


// Prefix sum + binary Search
// TC = O(nlogn)
// SC = O(n)

class Solution {
public:
    int minSubArrayLen(int k, vector<int>& v) {
        map<int, int> map;
        int n = v.size();
        map[0] = -1;
        int prev = 0;
        int res = 1e9;
        for(int i = 0; i < n; i++) {
            int pref = prev + v[i];
            int x = pref - k;
            map[pref] = i;
            auto it = map.lower_bound(x);
            if(it != map.end()) {
                if(it -> first == x) {
                    res = min(res, i - it -> second);
                } else {
                    if(it -> first != 0) {
                        it--;
                        res = min(res, i - it -> second);
                    }
                }
            }
            prev += v[i];
        }
        return res == 1e9 ? 0 : res;
    }
};