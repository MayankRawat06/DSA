class Solution {
public:
    int countCompleteSubarrays(vector<int>& v) {
        int n = v.size();
        unordered_set<int> t;
        unordered_map<int, int> map;
        for(int x : v) t.insert(x);
        int count = 0, i = 0;
        for(int j = 0; j < n; j++) {
            map[v[j]]++;
            while(map.size() == t.size()) {
                count += n - j;
                map[v[i]]--;
                if(map[v[i]] == 0) map.erase(v[i]);
                i++;
            }
        }
        return count;
    }
};