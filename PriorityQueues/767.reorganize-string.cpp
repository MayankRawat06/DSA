class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> map;
        priority_queue<pair<int, char>> pq;
        for(char c : s) map[c]++;
        for(auto it : map) {
            if(it.second > n / 2 && n % 2 == 0) return "";
            if(it.second > n / 2 + 1 && n % 2) return "";
            pq.push({it.second, it.first});
        }
        string res = "";
        char prev = 'A';
        while(!pq.empty()) {
            char c = pq.top().second;
            int freq = pq.top().first;
            pq.pop();
            if(c == prev) {
                c = pq.top().second;
                int pref = freq;
                freq = pq.top().first;
                pq.pop();
                pq.push({pref, prev});
            }
            if(c != prev) {
                res += c;
                freq--;
                if(freq > 0) pq.push({freq, c});
            }
            prev = c;
        }
        return res;
    }
};