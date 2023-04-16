class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()) {
            string s = q.front().first;
            int level = q.front().second;
            set.erase(s);
            q.pop();
            if(s == endWord) return level;
            for(int i = 0; i < s.size(); i++) {
                char og = s[i];
                for(int j = 0; j < 26; j++) {
                    s[i] = 'a' + j;
                    if(set.find(s) != set.end()) q.push({s, level + 1});
                }
                s[i] = og;
            }
        }
        return 0;
    }
};

