// construct and return all possible sentences after adding spaces 
// in the originally given string ‘S’, such that each word in a 
// sentence exists in the given dictionary.


void f(int index, string path, string &s, unordered_set<string>& set, vector<string>& res) {
    int n = s.size();
    if(index >= n) {
        res.push_back(path);
    }
    for(int i = index; i < n; i++) {
        string z = s.substr(index, i - index + 1);
        if(set.find(z) != set.end()) {
            if(i < n - 1) z = z + ' ';
            f(i + 1, path + z, s, set, res);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &d)
{
    // Write your code here
    unordered_set<string> set(d.begin(), d.end());
    vector<string> res;
    string path = "";
    f(0, path, s, set, res);
    return res;
}