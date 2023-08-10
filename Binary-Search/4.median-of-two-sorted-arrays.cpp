class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        if(v1.size() > v2.size()) return findMedianSortedArrays(v2, v1);
        int n1 = v1.size(), n2 = v2.size();
        int p = (n1 + n2 + 1) / 2;
        int low = 0, high = v1.size();
        while(low <= high) {
            int cut1 = low + (high - low) / 2, cut2 = p - cut1;
            int l1 = cut1 - 1 < 0 ? INT_MIN : v1[cut1 - 1];
            int l2 = cut2 - 1 < 0 ? INT_MIN : v2[cut2 - 1];
            int r1 = cut1 >= n1 ? INT_MAX : v1[cut1];
            int r2 = cut2 >= n2 ? INT_MAX : v2[cut2];
            if(l1 <= r2 && l2 <= r1) return (n1 + n2) % 2 ? max(l1, l2) : (max(l1, l2) + min(r1, r2)) / 2.0;
            else if(l1 > r2) high = cut1 - 1; // move left
            else low = cut1 + 1; // move right
        }
        return 0.0;
    }
};