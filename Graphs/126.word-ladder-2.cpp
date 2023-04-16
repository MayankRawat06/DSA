

// gives TLE 
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        vector<vector<string>> res;
        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        if(set.find(beginWord) != set.end()) set.erase(beginWord);
        while(!q.empty()) {
            auto v = q.front();
            string last = v.back();
            q.pop();
            if(last == endWord) {
                if(res.size() == 0) res.push_back(v);
                else if(res.size() > 0) {
                    if(v.size() == res[0].size())
                        res.push_back(v);
                    else if(v.size() > res[0].size()) break;
                }
            }
            for(int i = 0; i < last.size(); i++) {
                char og = last[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    last[i] = c;
                    if(set.find(last) != set.end()) {
                        v.push_back(last);
                        q.push(v);
                        v.pop_back();
                    }
                }
                last[i] = og;
                if(q.front().size() > v.size())
                    set.erase(last); 
            }
        }
        return res;
    }


// optimized

class Solution {
    void dfs(string word, vector<string>& path, vector<vector<string>>& res, unordered_map<string, int>& map) {
        int level = map[word];
        if(level == 1) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < word.size(); i++) {
            char og = word[i];
            for(char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if(map.find(word) != map.end() && map[word] < level) {
                    path.push_back(word);
                    dfs(word, path, res, map);
                    path.pop_back();
                }
            }
            word[i] = og;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> map;
        vector<vector<string>> res;
        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        map[beginWord] = 1;
        int level = 1;
        set.erase(beginWord);
        while(!q.empty()) {
            string word = q.front(); q.pop();
            level = map[word];
            if(word == endWord) break;
            for(int i = 0; i < word.size(); i++) {
                char og = word[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if(set.find(word) != set.end()) {
                        q.push(word);
                        map[word] = level + 1;
                        set.erase(word);
                    }
                }
                word[i] = og;
            }
        }
        if(map.find(endWord) != map.end()) {
            vector<string> path;
            path.push_back(endWord);
            dfs(endWord, path, res, map);
            for(vector<string>& v : res) reverse(v.begin(), v.end());
        }
        return res;
    }
};