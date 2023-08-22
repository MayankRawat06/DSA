class Solution {
public:
    int canCompleteCircuit(vector<int>& v, vector<int>& c) {
        int total = 0, sum = 0, n = v.size(), start = -1;
        for(int i = 0; i < n; i++) {
            sum += v[i] - c[i];
            if(sum < 0) {
                total += sum;
                sum = 0;
                start = i;
            }
        }
        if(total + sum < 0) return -1;
        return start + 1;
    }
};