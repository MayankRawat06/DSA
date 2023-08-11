class Solution{
    public:
    int kthElement(int v1[], int v2[], int n, int m, int k)
    {
        // n = v1.size(), m = v2.size()
        if(n > m) return kthElement(v2, v1, m, n, k); // choose always a small array to apply BS
        int low = max(k - m, 0), high = min(n, k); // edge cases -- important
        // low --- if no. of elements in v2 are less than k elements, we need minimum k - v2.size() elements from v1
        // high --- if no. elements in v1 are greater than k elements, we need only k elements 
        while(low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = k - cut1;
            int l1 = cut1 >= 1 ? v1[cut1 - 1] : INT_MIN;
            int l2 = cut2 >= 1 ? v2[cut2 - 1] : INT_MIN;
            int r1 = cut1 < n ? v1[cut1] : INT_MAX;
            int r2 = cut2 < m ? v2[cut2] : INT_MAX;
            if(l1 <= r2 && l2 <= r1) return max(l1, l2);
            else if(l1 > r2) high = cut1 - 1;
            else low = cut1 + 1;
        }
        return -1;
    }
};