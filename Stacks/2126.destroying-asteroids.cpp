class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& v) {
        sort(v.begin(), v.end());
        long long curr = mass;
        for(auto &a : v) {
            if(a <= curr) curr += a;
            else return false;
        }
        return true;
    }
};