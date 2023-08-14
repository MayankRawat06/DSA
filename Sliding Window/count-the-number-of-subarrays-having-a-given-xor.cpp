int Solution::solve(vector<int> &v, int k) { 
    unordered_map<int, int> map;
    int n = v.size();
    vector<int> xora(n);
    xora[0] = v[0];
    for(int i = 1; i < n; i++) xora[i] = xora[i - 1] ^ v[i];
    map[0] = 1;
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(map.count(k ^ xora[i])) res += map[k ^ xora[i]];
        map[xora[i]]++;
    }
    return res;
}
