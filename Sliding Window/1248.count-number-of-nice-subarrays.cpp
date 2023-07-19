class Solution {
public:
    int numberOfSubarrays(vector<int>& v, int k) {
        int n = v.size(), count = 0, odds = 0;
        unordered_map<int, int> map;
        vector<int> preodd(n);
        preodd[0] = v[0] % 2;
        map[0]++;
        if(k == 1) count += preodd[0];
        map[preodd[0]]++;
        for(int i = 1; i < n; i++) {
            preodd[i] = preodd[i - 1] + (v[i] % 2);
            if(map.find(preodd[i] - k) != map.end()) count += map[preodd[i] - k];
            map[preodd[i]]++;
        }
        return count;
    }
};