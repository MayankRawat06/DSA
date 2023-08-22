//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& v, int n) 
    {
        // code here 
        stack<int> s;
        for(int i = 0; i < n; i++) s.push(i);
        while(s.size() > 1) {
            int first = s.top(); s.pop();
            int second = s.top(); s.pop();
            if(v[first][second] == 1) s.push(second); // if A knows B -- A can't be a celeb
            else s.push(first);
        }
        int k = s.top();
        for(int i = 0; i < n; i++) if(v[k][i] || (i != k && v[i][k] == 0)) return -1;
        return k;
    }
};