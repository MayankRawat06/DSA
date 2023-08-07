

class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > v, int m, int n, int x) 
    {
        // code here 
        int i = 0, j = n - 1;
        while(i < n && j >= 0) {
            if(v[i][j] == x) return true;
            else if(v[i][j] > x) j--; // go left
            else i++; // go down
        }
        return false;
    }
};