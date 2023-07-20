class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0, n = s.size(), count = 0;
        vector<int> v(3, 0);
        for(int j = 0; j < n; j++) {
            v[s[j] - 'a']++;
            while(v[0] && v[1] && v[2]) {
                count += n - j;
                v[s[i] - 'a']--;
                i++;
            }
        }
        return count;
    }
};