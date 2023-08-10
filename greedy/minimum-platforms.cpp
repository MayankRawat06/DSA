class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int a[], int d[], int n)
    {
    	// Your code here
    	int res = 0;
    	sort(a, a + n);
    	sort(d, d + n);
    	int j = 0; // track dep
    	int count = 1;
    	for(int i = 1; i < n; i++) { // track arr
    	    while(j < n && d[j] < a[i]) {
    	        j++;
    	        count--;
    	    }
    	    count++;
    	    res = max(res, count);
    	}
    	return res;
    }
};