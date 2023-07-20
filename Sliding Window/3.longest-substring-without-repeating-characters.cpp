class Solution {
public:
    int lengthOfLongestSubstring(string v) {
        int n = v.size(), i = 0, res = 0;
        unordered_map<char, int> map;
        for(int j = 0; j < n; j++) {
            map[v[j]]++;
            while(i < n && map[v[j]] > 1) {
                map[v[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};