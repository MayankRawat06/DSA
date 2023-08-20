class Solution {
public:
    int ladderLength(string b, string e, vector<string>& w) {
        unordered_set<string> set(w.begin(), w.end());
        int n = b.size();
        queue<pair<string, int>> q;
        q.push({b, 1});
        while(!q.empty()) {
            string s = q.front().first;
            int level = q.front().second;
            q.pop();
            set.erase(s);
            if(s == e) return level;
            for(int i = 0; i < n; i++) {
                char og = s[i];
                for(int k = 0; k < 26; k++) {
                    s[i] = k + 'a';
                    if(set.count(s)) q.push({s, level + 1});
                }
                s[i] = og;
            }
        }
        return 0;
    }
};