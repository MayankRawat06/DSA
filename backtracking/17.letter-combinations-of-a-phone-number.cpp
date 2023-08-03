class Solution {
    unordered_map<int, string> map;
    vector<string> res;
    void f(int index, string& path, string& s) {
        if(index >= s.size()) {
            res.push_back(path);
            return;
        }
        int d = s[index] - '0';
        for(char c : map[d]) {
            path += c;
            f(index + 1, path, s);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";
        string path = "";
        f(0, path, digits);
        return res;
    }
};