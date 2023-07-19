class Solution {
public:
    int numSubarraysWithSum(vector<int>& v, int goal) {
        int n = v.size();
        vector<int> pre(n);
        unordered_map<int, int> map;
        pre[0] = v[0];
        map[0] = 1;
        int count = 0;
        map[pre[0]]++;
        if(pre[0] == goal) count++;
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + v[i];
            if(map.find(pre[i] - goal) != map.end()) count += map[pre[i] - goal];
            map[pre[i]]++;
        }
        return count;
    }
};