class Solution {
  public:
    int findSubArraySum(int k, vector<int> &v) {
        // code here
        unordered_map<int, int> map;
        int n = v.size();
        map[0] = 1;
        int prev = 0;
        int res = 0;
        for(int i = 0; i < n; i++) {
            int pref = prev + v[i];
            if(map.find(pref - k) != map.end()) res += map[pref-k];
            map[pref]++;
            prev += v[i];
        }
        return res;
    }
};