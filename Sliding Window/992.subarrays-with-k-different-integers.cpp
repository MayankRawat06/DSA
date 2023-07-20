class Solution {
    int atMostK(vector<int>& v, int k) {
        int n = v.size(), count = 0, i = 0;
        unordered_map<int, int> map;
        for(int j = 0; j < n; j++) {
            map[v[j]]++;
            while(i < n && map.size() > k) {
                map[v[i]]--;
                if(map[v[i]] == 0) map.erase(v[i]);
                i++;
            }
            count += (j - i + 1);
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& v, int k) {
        return atMostK(v, k) - atMostK(v, k - 1);
    }
};