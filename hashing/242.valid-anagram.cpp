class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> map(26, 0);
        for(char c : s) map[c - 'a']++;
        for(char c : t) map[c - 'a']--;
        for(int i = 0; i < 26; i++) {
            if(map[i] != 0) return false;
        }
        return true;
    }
};