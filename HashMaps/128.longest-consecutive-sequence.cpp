class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        if(v.size() == 0) return 0;
        unordered_set<int> set;
        for(int x : v) set.insert(x);
        int maxi = 1;
        for(auto it : set) {
            if(!set.count(it - 1)) {
                int s = it;
                int curr = 1;
                while(set.count(s + 1)) {
                    s += 1;
                    curr += 1;
                }
                maxi = max(curr, maxi);
            }
        }
        return maxi;
    }
};