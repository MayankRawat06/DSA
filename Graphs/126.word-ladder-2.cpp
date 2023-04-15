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
