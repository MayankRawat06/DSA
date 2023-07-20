class Solution {
public:
    int totalFruit(vector<int>& v) {
        int res = 0, i = 0, n = v.size();
        unordered_map<int, int> map;
        for(int j = 0; j < n; j++) {
            map[v[j]]++;
            while(i < n && map.size() > 2) {
                map[v[i]]--;
                if(map[v[i]] == 0) map.erase(v[i]);
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};