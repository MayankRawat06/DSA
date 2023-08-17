class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if(m > n) return false;
        vector<int> v1(26, 0), v2(26, 0);
        for(char c : s1) v1[c - 'a']++;
        for(int i = 0; i < n; i++) {
            if(i < m) v2[s2[i] - 'a']++;
            else {
                v2[s2[i - m] - 'a']--;
                v2[s2[i] - 'a']++;
            }
            if(v1 == v2) return true;
        }
        return false;
    }
};