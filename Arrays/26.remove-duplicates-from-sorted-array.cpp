class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int n = v.size(), i = 0, j = 1; 
        while(i < n && j < n) {
            if(v[i] == v[j]) j++;
            else {
                v[i + 1] = v[j];
                i++;
            }
        }
        return i + 1;
    }
};