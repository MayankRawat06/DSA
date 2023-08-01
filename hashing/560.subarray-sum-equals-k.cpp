class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int n = v.size();
        unordered_map<int, int> map;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(i > 0)
                v[i] += v[i - 1];
        }
        for(int x : v) {
            if(x == k) count++;
            if(map.find(x - k) != map.end()) count += map[x - k];
            map[x]++;
        }
        return count;
    }
};