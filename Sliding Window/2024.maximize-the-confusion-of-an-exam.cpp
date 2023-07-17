class Solution {
    int f(string& v, int k, char c) {
        int n = v.size();
        int count = 0;
        int i = 0, j = 0;
        int res = 0;
        while(j < n) {
            if(v[j] == c) {
                count++;
                if(count > k) {
                    while(v[i] != c) i++;
                    i++;
                }
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
public:
    int maxConsecutiveAnswers(string v, int k) {
        // case 1 : f -> t 
        // case 2 : t -> f
        int res = 0;
        res = max(f(v, k, 'T'), f(v, k, 'F'));
        return res;
    }
};
