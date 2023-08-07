class Solution {
public:
    int majorityElement(vector<int>& v) {
        // Moore's Voting
        int n = v.size(), ele = v[0], count = 0;
        for(int i = 0; i < n; i++) {
            if(count == 0) {
                ele = v[i];
                count = 1;
            }
            else {
                if(v[i] == ele) count++;
                else count--;
            }
        }
        int freq = 0;
        for(int x : v) if(x == ele) freq++;
        return freq > n / 2 ? ele : -1;
    }
};