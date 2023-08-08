class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int n = v.size();
        if(n == 1) return;
        int index1 = -1, index2 = -1;
        // find element that is less than its previous element -- doing reverse iteration
        for(int i = n - 2; i >= 0; i--) {
            if(v[i] < v[i + 1]) {
                index1 = i; 
                break;
            }
        }
        // if the array is decreasing
        if(index1 == -1) {
            reverse(v.begin(), v.end());
            return;
        }
        // find element just greater than the element at index1 -- doing reverse iteration
        for(int i = n - 1; i >= 0; i--) {
            if(v[i] > v[index1]) {
                index2 = i;
                break;
            }
        }
        // swap these elements
        swap(v[index1], v[index2]);
        // reverse the enitire array after index + 1 (inclusive)
        if(v.begin() + index1 + 1 < v.end()) reverse(v.begin() + index1 + 1, v.end());
    }
};
