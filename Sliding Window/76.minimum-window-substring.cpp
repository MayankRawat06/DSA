class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> map;
        for(char c : t) map[c]++;
        int i = 0;
        int n = s.size(), count = t.size();
        int mini = 1e9, minS = -1;
        for(int j = 0; j < n; j++) {
            if(map[s[j]] > 0) {
                count--;
            }
            map[s[j]]--;
            while(i <= j && count == 0) {
                if(mini > j - i + 1) {
                    minS = i;
                    mini = j - i + 1;
                }
                map[s[i]]++;
                if(map[s[i]] > 0) {
                    count++;
                }
                i++;
            }
        }
        return minS != -1 ? s.substr(minS, mini) : "";
    }
};