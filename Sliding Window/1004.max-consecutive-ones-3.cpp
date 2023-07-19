class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int i = 0, n = v.size(), x = 0, res = 0;
        for(int j = 0; j < n; j++) {
            if(v[j] == 0) x++;
            while(i < n && x > k) {
                if(v[i] == 0) x--;
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res; 
    }
};