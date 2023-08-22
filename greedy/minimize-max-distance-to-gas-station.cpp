class Solution {
  public:
    double findSmallestMaxDist(vector<int> &v, int k){
      // Code here
        int n = v.size();
        priority_queue<pair<double, int>> pq;
        vector<int> freq(n - 1, 0);
        for(int i = 0; i < n - 1; i++) 
            pq.push({v[i + 1] - v[i], i});
        while(k--) {
            double maxi = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            double initial = v[index + 1] - v[index];
            freq[index]++;
            double newlen = initial / (freq[index] + 1);
            pq.push({newlen, index});
        }
        return pq.top().first;
    }
};