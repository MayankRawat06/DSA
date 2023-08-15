class Solution {
public:
    vector<int> pivotArray(vector<int>& v, int p) {
        int n = v.size();
        vector<int> res(n);
        int low = 0, mid = 0, high = 0;
        for(int x : v) {
            if(x < p) mid++;
            else if(x == p) high++;
        }
        high += mid;
        for(int x : v) {
            res[x < p ? low++ : x == p ? mid++ : high++] = x;
        }
        return res;
    }
};