class Solution {
    int n, res;
public:
    void f(int index, vector<int>& v) {
        if(index >= n) {
            res += 1;
            return;
        }
        for(int i = index; i < n; i++) {
            swap(v[index], v[i]); 
            if(v[index] % (index + 1) == 0 || (index + 1) % v[index] == 0) f(index + 1, v); // here we're looking for element to be put at current index, that's why we use the above check.
            swap(v[index], v[i]);
        }
    }
    int countArrangement(int N) {
        vector<int> v;
        for(int i = 1; i <= N; i++) v.push_back(i);
        n = v.size(), res = 0;
        f(0, v);
        return res;
    }
};